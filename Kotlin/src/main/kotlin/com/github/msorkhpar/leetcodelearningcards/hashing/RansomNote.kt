package com.github.msorkhpar.leetcodelearningcards.hashing

class RansomNote {
    fun canConstruct(ransomNote: String, magazine: String): Boolean {
        val magazineMap = magazine.groupingBy { it }.eachCountTo(mutableMapOf())
        for (character in ransomNote) {
            val frequency = magazineMap[character]?: 0
            if (frequency <= 0) {
                return false
            }
            magazineMap[character] = frequency - 1;
        }
        return true
    }
}