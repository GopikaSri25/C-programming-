struct Node* copyRandomList(struct Node *head) {
    if(head == NULL) return NULL;
    struct Node *newHead = (struct Node *)malloc(sizeof(struct Node));
    newHead->val = head->val; newHead->next = NULL;
    newHead->random = head->random;
    head->random = newHead;
    struct Node *n1 = newHead, *new;
    for(struct Node *n2 = head->next; n2; n2 = n2->next){
        new = (struct Node *)malloc(sizeof(struct Node));
        new->val = n2->val;
        new->random = n2->random;
        n2->random = new;
        n1->next = new;
        n1 = new;
    }
    n1->next=NULL;
    for(n1 = newHead;n1; n1=n1->next)
        if(n1->random)
            n1->random = n1->random->random;
    return newHead;
}
