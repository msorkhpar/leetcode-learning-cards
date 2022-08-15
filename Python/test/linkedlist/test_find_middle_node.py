import unittest
from parameterized import parameterized

from src.linkedlist.find_middle_node import FindMiddleNode
from src.linkedlist.find_middle_node import ListNode


def convert_input_data_to_linked_list(data: list) -> ListNode:
    head: ListNode = None
    tail: ListNode = None
    for item in data:
        node = ListNode(item)
        if head is None:
            head = node
            tail = node
        else:
            tail.next = node
            tail = node
    return head


class FindMiddleNodeTest(unittest.TestCase):

    @parameterized.expand([
        ([1, 2, 3, 4, 5], 3),
        ([1, 2, 3, 4, 5, 6], 4),
    ])
    def test_actual_return_against_expected(self, data, expected):
        converted_data = convert_input_data_to_linked_list(data)
        actual = FindMiddleNode().middle_node(converted_data)
        self.assertEqual(actual.val, expected)


if __name__ == '__main__':
    unittest.main()
