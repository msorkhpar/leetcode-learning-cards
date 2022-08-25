package com.github.msorkhpar.leetcodelearningcards.array

fun hasEvenNumberOfDigits(num: Int): Boolean {
    if (num < 2) {
        return false
    }
    var dividable = num
    var numberOfDigits = 0
    while (dividable > 0) {

        numberOfDigits += 1
        dividable /= 10
    }
    return numberOfDigits % 2 == 0
}


class EvenNumberOfDigitsTestTestCases {
    fun findNumbers(nums: IntArray): Int {
        var result = 0
        for (num in nums) {
            if (
                hasEvenNumberOfDigits(num)) {
                result++
            }
        }
        return result
    }
}