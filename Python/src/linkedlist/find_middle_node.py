from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class FindMiddleNode:

    def middle_node(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow_pointer = fast_pointer = head
        while fast_pointer.next is not None:
            slow_pointer = slow_pointer.next
            fast_pointer = fast_pointer.next
            if fast_pointer.next is not None:
                fast_pointer = fast_pointer.next
        return slow_pointer
