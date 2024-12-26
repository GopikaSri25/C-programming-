
bool hasCycle(struct ListNode *head) {
if(head==NULL)
    return false;

  if(head-> next == NULL)
        return false;
   struct  ListNode* slow = head;
   struct  ListNode* fast = head;
     while(slow != NULL && fast != NULL){
         fast = fast->next;
         if(fast != NULL)
             fast = fast->next;
         slow = slow-> next;
         if(slow == fast)
             return true;
     }
    return false;
  

}
