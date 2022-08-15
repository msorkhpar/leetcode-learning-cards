package com.github.msorkhpar.leetcodelearningcards.linkedlist

class ListNode(var `val`: Int) {
    var next: ListNode? = null
}

class FindMiddleNode {
    fun middleNode(head: ListNode): ListNode {
        var slowPointer:ListNode? = head
        var fastPointer:ListNode? = head
        while (fastPointer?.next != null) {
            slowPointer = slowPointer?.next
            fastPointer = fastPointer.next?.next
        }
        return slowPointer!!
    }
}