package com.github.msorkhpar.leetcodelearningcards.linkedlist

import org.assertj.core.api.Assertions.assertThat

import org.junit.jupiter.params.ParameterizedTest
import org.junit.jupiter.params.provider.Arguments
import org.junit.jupiter.params.provider.MethodSource

internal class FindMiddleNodeTest {
    companion object {
        @JvmStatic
        fun parametersProvider() = listOf(
            Arguments.of(intArrayOf(1, 2, 3, 4, 5), 3),
            Arguments.of(intArrayOf(1, 2, 3, 4, 5, 6), 4),
        )
    }

    @ParameterizedTest
    @MethodSource("parametersProvider")
    fun `middleNode should return the expected value`(input: IntArray, expected: Int) {
        val convertedData = convertInputDataToLinkedList(input)
        val actual = FindMiddleNode().middleNode(convertedData)

        assertThat(actual.`val`).isEqualTo(expected)
    }
}

fun convertInputDataToLinkedList(data: IntArray): ListNode {
    var head: ListNode? = null
    var tail: ListNode? = null
    for (item in data) {
        val node = ListNode(item)
        if (head == null) {
            head = node
            tail = node
        } else {
            tail!!.next = node
            tail = node
        }
    }
    return head!!
}