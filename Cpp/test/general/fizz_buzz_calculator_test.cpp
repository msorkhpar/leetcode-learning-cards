#include <iostream>
#include <vector>

#include "gtest/gtest.h"
#include "general/fizz_buzz_calculator.h"
#include "general/fizz_buzz_calculator.c"

using namespace std;

struct FizzBuzzCalculatorTest_test_data {
    int input;
    std::vector<std::string> expected;
};

struct FizzBuzzCalculatorTest : public testing::TestWithParam<FizzBuzzCalculatorTest_test_data> {
};

INSTANTIATE_TEST_SUITE_P(FizzBuzzCalculatorTestTestCases, FizzBuzzCalculatorTest,
                         testing::Values(
                                 FizzBuzzCalculatorTest_test_data{3, {"1", "2", "Fizz"}},
                                 FizzBuzzCalculatorTest_test_data{5, {"1", "2", "Fizz", "4", "Buzz"}},
                                 FizzBuzzCalculatorTest_test_data{15, {
                                         "1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11", "Fizz",
                                         "13", "14", "FizzBuzz"}}
                         )
);

TEST_P(FizzBuzzCalculatorTest, FizzBuzzCalculatorTestCppTestCase) {
    auto input = GetParam().input;
    auto const &expected = GetParam().expected;

    auto actual = FizzBuzzCalculator().FizzBuzz(input);

    ASSERT_EQ(actual, expected);
}

TEST_P(FizzBuzzCalculatorTest, FizzBuzzCalculatorTestCTestCase) {
    auto input = GetParam().input;
    auto const &expected = GetParam().expected;
    int return_size;
    char **result = fizz_buzz(input, &return_size);
    vector<string> actual(result, result + return_size);
    ASSERT_EQ(actual, expected);
}
