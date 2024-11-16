struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct Listnode* head;
    if(list1==NULL) return list2;
    if(list2==NULL) return list1;
    if (list1->val<=list2->val){
        head=list1;
        struct ListNode* curr=head;
        struct ListNode* currNext=NULL;
        if(curr->next!=NULL){
            currNext=curr->next;
        }
        struct ListNode* other=list2;
        struct ListNode* otherNext=NULL;
        if(list2->next!=NULL){
            otherNext=list2->next;
        }
        while(currNext!=NULL && other!=NULL){
            if(currNext->val<=other->val){
                curr=currNext;
                currNext=currNext->next;
            } else {
                curr->next=other;
                other->next=currNext;
                other=otherNext;
                if(other!=NULL && other->next!=NULL)
                    otherNext=other->next;
                else otherNext=NULL;
                curr=curr->next;
                currNext=curr->next;
            }
        }
        if(currNext==NULL && other!=NULL){
            curr->next=other;
        }
        
    } else{
        head=list2;
        struct ListNode* curr=head;
        struct ListNode* currNext=NULL;
        if(curr->next!=NULL){
            currNext=curr->next;
        }
        struct ListNode* other=list1;
        struct ListNode* otherNext=NULL;
        if(list1->next!=NULL){
            otherNext=list1->next;
        }
        while(currNext!=NULL && other!=NULL){
            if(currNext->val<=other->val){
                curr=currNext;
                currNext=currNext->next;
            } else {
                curr->next=other;
                other->next=currNext;
                other=otherNext;
                if(other!=NULL && other->next!=NULL)
                    otherNext=other->next;
                else otherNext=NULL;
                curr=curr->next;
                currNext=curr->next;
            }
        }
        if(currNext==NULL && other!=NULL){
            curr->next=other;
        }
    }
    return head;
}
