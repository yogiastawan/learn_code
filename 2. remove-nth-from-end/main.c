#include <stdio.h>

/**
 * Definition for singly-linked list.
 * */
struct ListNode {
    int val;
    struct ListNode* next;
};

typedef struct ListNode ListNode;

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    ListNode dummy = {
        0, head};
    ListNode* left = &dummy;
    ListNode* right = head;

    for (int i = 0; i < n; i++) {
        if (!left) break;
        right = right->next;
    }

    while (right) {
        left = left->next;
        right = right->next;
    }

    left->next = left->next->next;
    return dummy.next;
}

int main(int, char**) {
    ListNode node = {
        1, NULL};
    ListNode* head = &node;
    ListNode l2 = {2, NULL};
    ListNode l3 = {3, NULL};
    head->next = &l2;
    l2.next = &l3;
    return 0;
}
