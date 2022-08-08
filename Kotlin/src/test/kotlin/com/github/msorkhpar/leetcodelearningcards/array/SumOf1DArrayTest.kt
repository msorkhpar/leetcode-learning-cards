package com.github.msorkhpar.leetcodelearningcards.array


import org.assertj.core.api.Assertions.assertThat

import org.junit.jupiter.params.ParameterizedTest
import org.junit.jupiter.params.provider.Arguments
import org.junit.jupiter.params.provider.MethodSource

internal class SumOf1DArrayTest {
    companion object {
        @JvmStatic
        fun parametersProvider() = listOf(
            Arguments.of(intArrayOf(1, 1, 1, 1, 1), intArrayOf(1, 2, 3, 4, 5)),
            Arguments.of(intArrayOf(1, 2, 3, 4), intArrayOf(1, 3, 6, 10)),
            Arguments.of(intArrayOf(3, 1, 2, 10, 1), intArrayOf(3, 4, 6, 16, 17)),
        )
    }

    @ParameterizedTest
    @MethodSource("parametersProvider")
    fun runningSum(numbers: IntArray, expected: IntArray) {
        val actual = SumOf1DArray().runningSum(numbers)
        assertThat(actual).containsExactly(expected.toTypedArray())
    }
}