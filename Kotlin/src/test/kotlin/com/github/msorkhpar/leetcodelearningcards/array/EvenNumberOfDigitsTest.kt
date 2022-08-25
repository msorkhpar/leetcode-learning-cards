package com.github.msorkhpar.leetcodelearningcards.array

import org.assertj.core.api.Assertions.assertThat

import org.junit.jupiter.params.ParameterizedTest
import org.junit.jupiter.params.provider.Arguments
import org.junit.jupiter.params.provider.MethodSource

internal class EvenNumberOfDigitsTest {
    companion object {
        @JvmStatic
        fun parametersProvider() = listOf(
            Arguments.of(intArrayOf(0), 0),
            Arguments.of(intArrayOf(1771), 1),
            Arguments.of(intArrayOf(1772), 1),
            Arguments.of(intArrayOf(12, 345, 2, 6, 7896), 2),
            Arguments.of(intArrayOf(555, 901, 482, 1771), 1)
        )
    }

    @ParameterizedTest
    @MethodSource("parametersProvider")
    fun `findNumbers should return the expected value`(input: IntArray, expected: Int) {
        val actual = EvenNumberOfDigitsTestTestCases().findNumbers(input)
        assertThat(actual).isEqualTo(expected)
    }
}