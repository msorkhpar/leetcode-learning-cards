package com.github.msorkhpar.leetcodelearningcards.array

import kotlin.math.max

class RichestCustomerWealth {
    fun maximumWealth(accounts: Array<IntArray>): Int {
        var result = 0
        var currentAccountWealth: Int
        for (resources in accounts) {
            currentAccountWealth = 0
            for (resource in resources) {
                currentAccountWealth += resource
            }
            result = max(currentAccountWealth, result)
        }
        return result
    }
}