#include <iostream>
#include <vector>

#include "gtest/gtest.h"
#include "array/even_number_of_digits.h"
#include "array/even_number_of_digits.c"

struct EvenNumberOfDigitsTest_test_data {
    std::vector<int> input;
    int expected;
};

struct EvenNumberOfDigitsTest : public testing::TestWithParam<EvenNumberOfDigitsTest_test_data> {
};

INSTANTIATE_TEST_SUITE_P(EvenNumberOfDigitsTestTestCases, EvenNumberOfDigitsTest,
                         testing::Values(
                                 EvenNumberOfDigitsTest_test_data{{0}, 0},
                                 EvenNumberOfDigitsTest_test_data{{1771}, 1},
                                 EvenNumberOfDigitsTest_test_data{{1772}, 1},
                                 EvenNumberOfDigitsTest_test_data{{12, 345, 2, 6, 7896}, 2},
                                 EvenNumberOfDigitsTest_test_data{{555, 901, 482, 1771}, 1}
                         )
);

TEST_P(EvenNumberOfDigitsTest, EvenNumberOfDigitsTestCppTestCase) {
    auto input = GetParam().input;
    auto const &expected = GetParam().expected;

    auto actual = EvenNumberOfDigits().FindNumbers(input);

    ASSERT_EQ(actual, expected);
}

TEST_P(EvenNumberOfDigitsTest, EvenNumberOfDigitsTestCTestCase) {
    auto input = GetParam().input;
    auto const &expected = GetParam().expected;

    int actual = find_numbers(input.data(), input.size());

    ASSERT_EQ(actual, expected);
}
