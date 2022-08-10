package com.github.msorkhpar.leetcodelearningcards.general

import org.assertj.core.api.Assertions.assertThat

import org.junit.jupiter.params.ParameterizedTest
import org.junit.jupiter.params.provider.Arguments
import org.junit.jupiter.params.provider.MethodSource

internal class FizzBuzzCalculatorTest {
    companion object {
        @JvmStatic
        fun parametersProvider() = listOf(
            Arguments.of(3, listOf("1", "2", "Fizz")),
            Arguments.of(5, listOf("1", "2", "Fizz", "4", "Buzz")),
            Arguments.of(
                15, listOf(
                    "1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8",
                    "Fizz", "Buzz", "11", "Fizz", "13", "14", "FizzBuzz"
                )
            ),
        )
    }

    @ParameterizedTest
    @MethodSource("parametersProvider")
    fun `fizzBuzz should return the expected value`(input: Int, expected: List<String>) {
        val actual = FizzBuzzCalculator().fizzBuzz(input)
        assertThat(actual).isEqualTo(expected)
    }
}