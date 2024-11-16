struct ListNode *ptrs[10000];
int cmp(const void *a, const void *b)
{
    return (*((struct ListNode **)(a)))->val - (*((struct ListNode **)(b)))->val;
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    int total = 0;
    for (int i = 0; i < listsSize; i++) {
        for (struct ListNode *tmp = lists[i]; tmp; tmp = tmp->next) {
            ptrs[total] = tmp;
            total++;
        }        
    } 
    qsort(ptrs, total, sizeof(struct ListNode *), cmp); 
    for (int i = 0; i < total - 1; i++) {
        ptrs[i]->next = ptrs[i + 1];
    }
    if (total) {
        ptrs[total - 1]->next = NULL;
    }
    else {
        ptrs[0] = NULL;
    }  
    return ptrs[0];
}
