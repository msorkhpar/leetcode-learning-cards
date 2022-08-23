package com.github.msorkhpar.leetcodelearningcards.array

import org.assertj.core.api.Assertions.assertThat

import org.junit.jupiter.params.ParameterizedTest
import org.junit.jupiter.params.provider.Arguments
import org.junit.jupiter.params.provider.MethodSource

internal class MaxConsecutiveOnesTest {
    companion object {
        @JvmStatic
        fun parametersProvider() = listOf(
            Arguments.of(intArrayOf(1, 1, 0, 1, 1, 1), 3),
            Arguments.of(intArrayOf(1, 0, 1, 1, 0, 1), 2),
            Arguments.of(intArrayOf(1, 1, 1, 1, 1, 1), 6),
        )
    }

    @ParameterizedTest
    @MethodSource("parametersProvider")
    fun `findMaxConsecutiveOnes should return the expected value`(input: IntArray, expected: Int) {
        val actual = MaxConsecutiveOnes().findMaxConsecutiveOnes(input)
        assertThat(actual).isEqualTo(expected)
    }
}