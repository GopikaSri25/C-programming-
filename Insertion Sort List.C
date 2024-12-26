struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode *newlist = (struct ListNode *)calloc(1, sizeof(struct ListNode));

    newlist->val = INT_MIN;
    newlist->next = NULL;

    struct ListNode *trav = head;
    while(NULL != trav) {
        struct ListNode *prev = newlist;
        while(prev->next != NULL && trav->val > prev->next->val) {
            prev = prev->next;
        }
        struct ListNode *next = prev->next;
        struct ListNode *tmp = trav->next;
        prev->next = trav;
        trav->next = next;
        trav = tmp;
    }
    return newlist->next;    
}
