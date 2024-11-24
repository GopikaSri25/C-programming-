struct ListNode* rotateRight(struct ListNode* head, int k)
{
    if(head==NULL||head->next==NULL)
    {
        return(head);
    }
    int size=0;
    struct ListNode* temp = head;
    while(temp)
    {
        temp = temp->next;
        size++;
    }
    k = k%size;    
    for(int i=0;i<k;i++)
    {
        struct ListNode* temp = head;
        
        struct ListNode* prev = NULL;
        while(temp->next)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next=NULL;   
        temp->next = head; 
        head = temp; 
return(head);
}
