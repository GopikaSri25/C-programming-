struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = -1;
    dummy->next = head;

    struct ListNode* first = dummy;
    struct ListNode* second = dummy;

    for (int i = 1; i <= n + 1; i++) {
        first = first->next;
    }

    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    second->next = second->next->next;

    return dummy->next;
}
