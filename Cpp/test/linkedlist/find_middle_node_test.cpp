#include <iostream>
#include <vector>

#include "gtest/gtest.h"
#include "linkedlist/find_middle_node.h"
#include "linkedlist/find_middle_node.c"

struct FindMiddleNodeTest_test_data {
    std::vector<int> input;
    int expected;
};

struct FindMiddleNodeTest : public testing::TestWithParam<FindMiddleNodeTest_test_data> {
};

INSTANTIATE_TEST_SUITE_P(FindMiddleNodeTestTestCases, FindMiddleNodeTest,
                         testing::Values(
                                 FindMiddleNodeTest_test_data{{1, 2, 3, 4, 5}, 3},
                                 FindMiddleNodeTest_test_data{{1, 2, 3, 4, 5, 6}, 4}
                         )
);

struct CListNode *convert_to_Clinked_list(const std::vector<int> &input) {
    struct CListNode *head = nullptr;
    struct CListNode *tail = nullptr;
    for (auto item: input) {
        auto node = (struct CListNode *) malloc(sizeof(struct CListNode));
        node->val = item;
        node->next = nullptr;
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

struct ListNode *convert_to_linked_list(const std::vector<int> &input) {
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    for (auto item: input) {
        auto node = new ListNode();
        node->val = item;
        node->next = nullptr;
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

TEST_P(FindMiddleNodeTest, FindMiddleNodeTestCppTestCase) {
    auto input = GetParam().input;
    auto const &expected = GetParam().expected;
    ListNode *converted_input = convert_to_linked_list(input);

    auto actual = FindMiddleNode().MiddleNode(converted_input);

    ASSERT_EQ(actual->val, expected);
    free(converted_input);
}

TEST_P(FindMiddleNodeTest, FindMiddleNodeTestCTestCase) {
    auto input = GetParam().input;
    auto const &expected = GetParam().expected;
    CListNode *converted_input = convert_to_Clinked_list(input);

    CListNode const *actual = middle_node(converted_input);

    ASSERT_EQ(actual->val, expected);
}
