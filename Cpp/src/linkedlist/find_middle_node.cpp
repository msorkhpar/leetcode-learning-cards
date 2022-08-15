#include <iostream>
#include "find_middle_node.h"

using namespace std;

ListNode *FindMiddleNode::MiddleNode(ListNode *head) {
    ListNode *slow_pointer;
    ListNode *fast_pointer;
    if (head->next == nullptr) {
        return head;
    }
    slow_pointer = fast_pointer = head;

    while (fast_pointer->next) {
        slow_pointer = slow_pointer->next;
        fast_pointer = fast_pointer->next;
        if (fast_pointer->next) {
            fast_pointer = fast_pointer->next;
        }
    }

    return slow_pointer;
}
