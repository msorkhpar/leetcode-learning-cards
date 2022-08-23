package com.github.msorkhpar.leetcodelearningcards.array

import kotlin.math.max


class MaxConsecutiveOnes {

    fun findMaxConsecutiveOnes(nums: IntArray): Int {
        //nums.joinToString("").split("0").maxBy{ it.length }?.length ?:0
        var maxConsecutiveOnes = 0
        var counter = 0
        nums.forEach {
            if (it != 0)
                counter++
            else {
                maxConsecutiveOnes = max(counter, maxConsecutiveOnes)
                counter = 0
            }
        }
        maxConsecutiveOnes = max(counter, maxConsecutiveOnes)

        return maxConsecutiveOnes
    }
}
