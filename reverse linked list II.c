struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (left == right || head == NULL || head->next == NULL)
        return head;
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* Left = &dummy;
    for (int i = 1; i < left; i++) {
        Left = Left->next;
    }
    struct ListNode* current = Left->next;
    struct ListNode* nextNode;
    for (int i = left; i < right; i++) {
        nextNode = current->next;
        current->next = nextNode->next;
        nextNode->next = Left->next;
        Left->next = nextNode;
    }
    return dummy.next;
}
