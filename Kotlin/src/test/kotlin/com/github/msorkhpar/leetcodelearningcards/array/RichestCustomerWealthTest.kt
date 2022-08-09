package com.github.msorkhpar.leetcodelearningcards.array

import org.assertj.core.api.Assertions.assertThat

import org.junit.jupiter.params.ParameterizedTest
import org.junit.jupiter.params.provider.Arguments
import org.junit.jupiter.params.provider.MethodSource

internal class RichestCustomerWealthTest {
    companion object {
        @JvmStatic
        fun parametersProvider() = listOf(
            Arguments.of(
                arrayOf(
                    intArrayOf(1, 5),
                    intArrayOf(7, 3),
                    intArrayOf(3, 5),
                ), 10
            ),
            Arguments.of(
                arrayOf(
                    intArrayOf(1, 2, 3),
                    intArrayOf(3, 2, 1),
                ), 6
            ),
            Arguments.of(
                arrayOf(
                    intArrayOf(2, 8, 7),
                    intArrayOf(7, 1, 3),
                    intArrayOf(1, 9, 5),
                ), 17
            ),
        )
    }

    @ParameterizedTest
    @MethodSource("parametersProvider")
    fun `maximumWealth should return the expected value`(input: Array<IntArray>, expected: Int) {
        val actual = RichestCustomerWealth().maximumWealth(input)
        assertThat(actual).isEqualTo(expected)
    }
}