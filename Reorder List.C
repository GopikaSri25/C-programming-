void reorderList(struct ListNode* head) {
    struct ListNode *slow = head, *fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode* second = slow->next;
    struct ListNode* prev = slow->next = NULL;
    while (second) {
        struct ListNode* tmp = second->next;
        second->next = prev;
        prev = second;
        second = tmp;
    }
    struct ListNode* first = head;
    second = prev;
    while (second) {
        struct ListNode *tmp1 = first->next, *tmp2 = second->next;
        first->next = second;
        second->next = tmp1;
        first = tmp1, second = tmp2;
    }
}
