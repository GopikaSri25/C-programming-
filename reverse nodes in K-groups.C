struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* current = head;
    int count = 0;
    while (count < k && current) {
        current = current->next;
        count++;
    }
    if (count < k) {
        return head;
    }
    struct ListNode* prev = NULL;
    struct ListNode* next_node = NULL;
    current = head;
    for (int i = 0; i < k; i++) {
        next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }
    head->next = reverseKGroup(current, k);
    
    return prev;
}
