#include <iostream>
#include <list>
#include <vector>

#include "gtest/gtest.h"
#include "array/sum_of_1d_array.h"


struct SumOf1DArrayTest : public testing::TestWithParam<std::tuple<std::vector<int>, std::vector<int>>> {
};

INSTANTIATE_TEST_SUITE_P(
        SumOf1DArrayTestCases,
        SumOf1DArrayTest,
        testing::Values(
                std::make_tuple(std::vector<int>{1, 1, 1, 1, 1}, std::vector<int>{1, 2, 3, 4, 5}),
                std::make_tuple(std::vector<int>{1, 2, 3, 4}, std::vector<int>{1, 3, 6, 10}),
                std::make_tuple(std::vector<int>{3, 1, 2, 10, 1}, std::vector<int>{3, 4, 6, 16, 17}
                )
        )
);

TEST_P(SumOf1DArrayTest, SumOf1DArrayTestCase) {
    auto numbers = std::get<0>(GetParam());
    auto const& expected = std::get<1>(GetParam());

    auto actual = SumOf1DArray().RunningSum(numbers);
    ASSERT_EQ(actual, expected);
}