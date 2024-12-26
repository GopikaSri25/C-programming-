
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL)
        return NULL;

    struct ListNode* A = headA;
    struct ListNode* B = headB;

    while (A != B) {
        A = A == NULL ? headB : A->next;
        B = B == NULL ? headA : B->next;
    }

    return A;
    
}
