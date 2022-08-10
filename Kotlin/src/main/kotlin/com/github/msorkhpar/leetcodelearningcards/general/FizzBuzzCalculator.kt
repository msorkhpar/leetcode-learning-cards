package com.github.msorkhpar.leetcodelearningcards.general

class FizzBuzzCalculator {
    fun fizzBuzz(input: Int): List<String> {
        val result = ArrayList<String>()
        for (i in 1 until input + 1) {
            if (i % 3 == 0) {
                if (i % 5 == 0) {
                    result.add("FizzBuzz")
                } else {
                    result.add("Fizz")
                }
            } else if (i % 5 == 0) {
                result.add("Buzz")
            } else {
                result.add(i.toString())

            }
        }
        return result
    }
}