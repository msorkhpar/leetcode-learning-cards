#include <stdio.h>

struct CListNode {
    int val;
    struct CListNode *next;
};

struct CListNode *middle_node(struct CListNode *head) {
    struct CListNode *slow_pointer;
    struct CListNode *fast_pointer;
    if (head->next == NULL) {
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
