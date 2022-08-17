#include <iostream>
#include <vector>

#include "gtest/gtest.h"
#include "array/max_consecutive_ones.h"
#include "array/max_consecutive_ones.c"

struct MaxConsecutiveOnesTest_test_data {
    std::vector<int> input;
    int expected;
};

struct MaxConsecutiveOnesTest : public testing::TestWithParam<MaxConsecutiveOnesTest_test_data> {
};

INSTANTIATE_TEST_SUITE_P(MaxConsecutiveOnesTestTestCases, MaxConsecutiveOnesTest,
                         testing::Values(
                                 MaxConsecutiveOnesTest_test_data{{1, 1, 0, 1, 1, 1}, 3},
                                 MaxConsecutiveOnesTest_test_data{{1, 0, 1, 1, 0, 1}, 2},
                                 MaxConsecutiveOnesTest_test_data{{1, 1, 1, 1, 1, 1}, 6}

                         )
);

TEST_P(MaxConsecutiveOnesTest, MaxConsecutiveOnesTestCppTestCase) {
    auto input = GetParam().input;
    auto const &expected = GetParam().expected;

    auto actual = MaxConsecutiveOnes().FindMaxConsecutiveOnes(input);

    ASSERT_EQ(actual, expected);
}

TEST_P(MaxConsecutiveOnesTest, MaxConsecutiveOnesTestCTestCase) {
    auto input = GetParam().input;
    auto const &expected = GetParam().expected;

    int actual = find_max_consecutive_ones(input.data(), input.size());

    ASSERT_EQ(actual, expected);
}
