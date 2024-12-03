struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head == NULL || head->next == NULL) return head;
    
    struct ListNode* temp = head->next;
    
    bool check = false;
    while(temp!= NULL && head->val == temp->val){
        temp = temp->next;
        check = true;
    }
    temp = deleteDuplicates(temp);
    head->next = temp;
    if(check) head = head->next;
    
    return head;
}
