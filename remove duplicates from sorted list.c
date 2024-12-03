struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* temp=head;
    while (temp&&temp->next)
    {
        if (temp->next->val==temp->val)
        {
            temp->next=temp->next->next;
            continue;
        }
        temp=temp->next;
    }
    return head;
}
