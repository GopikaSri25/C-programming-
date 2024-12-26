struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *p1 = head, *p2 = head;
    while (p2 && p2->next) {
        p1 = p1->next;          
        p2 = p2->next->next;   
        if (p1 == p2) break;
    }
    if (!(p2 && p2->next)) return NULL;
    while (head != p1) {
        head = head->next;     
        p1 = p1->next;      
    }
    return head;       
}
