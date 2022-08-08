#include <iostream>
#include <list>
#include <vector>

#include "gtest/gtest.h"
#include "array/sum_of_1d_array.h"
#include "array/sum_of_1d_array.c"

struct SumOf1DArray_test_data {
    std::vector<int> numbers;
    std::vector<int> result;
};

struct SumOf1DArrayTest : public testing::TestWithParam<SumOf1DArray_test_data> {
};

INSTANTIATE_TEST_SUITE_P(
        SumOf1DArrayTestCases,
        SumOf1DArrayTest,
        testing::Values(
                SumOf1DArray_test_data{{1, 1, 1, 1, 1},
                                       {1, 2, 3, 4, 5}},
                SumOf1DArray_test_data{{1, 2, 3, 4},
                                       {1, 3, 6, 10}},
                SumOf1DArray_test_data{{3, 1, 2, 10, 1},
                                       {3, 4, 6, 16, 17}}
        )
);

TEST_P(SumOf1DArrayTest, SumOf1DArrayCppTestCase) {
    auto numbers = GetParam().numbers;
    auto const &expected = GetParam().result;

    auto actual = SumOf1DArray::RunningSum(numbers);
    ASSERT_EQ(actual, expected);
}

TEST_P(SumOf1DArrayTest, SumOf1DArrayCTestCase) {
    auto numbers = GetParam().numbers;
    auto const &expected = GetParam().result;

    int return_size;
    int *result = runningSum(numbers.data(), numbers.size(), &return_size);
    std::vector<int> actual(result, result + return_size);
    ASSERT_EQ(actual, expected);
}