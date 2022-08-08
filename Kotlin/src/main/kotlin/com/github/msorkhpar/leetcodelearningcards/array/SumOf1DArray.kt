package com.github.msorkhpar.leetcodelearningcards.array

class SumOf1DArray {
    fun runningSum(nums: IntArray): IntArray {
        for (index in 1 until nums.size) {
            nums[index] += nums[index - 1]
        }
        return nums
    }
}