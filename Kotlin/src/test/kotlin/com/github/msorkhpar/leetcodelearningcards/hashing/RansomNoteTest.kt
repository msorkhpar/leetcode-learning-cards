package com.github.msorkhpar.leetcodelearningcards.hashing

import org.assertj.core.api.Assertions.assertThat

import org.junit.jupiter.params.ParameterizedTest
import org.junit.jupiter.params.provider.Arguments
import org.junit.jupiter.params.provider.MethodSource

internal class RansomNoteTest {
    companion object {
        @JvmStatic
        fun parametersProvider() = listOf(
            Arguments.of("a", "b", false),
            Arguments.of("aa", "ab", false),
            Arguments.of("aa", "aab", true),
        )
    }

    @ParameterizedTest
    @MethodSource("parametersProvider")
    fun `canConstruct should return the expected value`(ransomNote: String, magazine: String, expected: Boolean) {
        val actual = RansomNote().canConstruct(ransomNote, magazine)
        assertThat(actual).isEqualTo(expected)
    }
}