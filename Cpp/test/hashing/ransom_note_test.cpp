#include <iostream>
#include <vector>

#include "gtest/gtest.h"
#include "hashing/ransom_note.h"
#include "hashing/ransom_note.c"

struct RansomNoteTest_test_data {
    std::string ransomNote;
    std::string magazine;
    bool expected;
};

struct RansomNoteTest : public testing::TestWithParam<RansomNoteTest_test_data> {
};

INSTANTIATE_TEST_SUITE_P(RansomNoteTestTestCases, RansomNoteTest,
                         testing::Values(
                                 RansomNoteTest_test_data{"a", "b", false},
                                 RansomNoteTest_test_data{"aa", "ab", false},
                                 RansomNoteTest_test_data{"aa", "aab", true}
                         )
);

TEST_P(RansomNoteTest, RansomNoteTestCppTestCase) {
    auto ransomNote = GetParam().ransomNote;
    auto magazine = GetParam().magazine;
    auto const &expected = GetParam().expected;

    auto actual = RansomNote().CanConstruct(ransomNote,magazine);

    ASSERT_EQ(actual, expected);
}

TEST_P(RansomNoteTest, RansomNoteTestCTestCase) {
    auto ransomNote = GetParam().ransomNote;
    auto magazine = GetParam().magazine;
    auto const &expected = GetParam().expected;

    bool actual = can_construct(ransomNote.data(), magazine.data());

    ASSERT_EQ(actual, expected);
}
