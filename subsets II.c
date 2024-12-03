struct node{
    int* val;
    struct node* next;
    int size;
};
typedef struct _stack{
    struct node* top;
    int size;
}Stack;
void push(Stack* stack,int* subset,int subsetSize){
    int* copy=malloc(subsetSize*sizeof(int));
    for(int i=0;i<subsetSize;i++){
        copy[i]=subset[i];
    }
    struct node* newNode=malloc(sizeof(struct node));
    newNode->val=copy;
    newNode->next=stack->top;
    newNode->size=subsetSize;
    stack->top=newNode;
    stack->size++;
}
int* pop(Stack* stack){
    stack->size--;
    int* subset=stack->top->val;
    stack->top=stack->top->next;
    return subset;
}
void backtrack(Stack* stack,int* subset,int subsetSize,int* nums,int numsSize,int start){
    push(stack,subset,subsetSize);
    for(int i=start;i<numsSize;i++){
        if(i>start && nums[i]==nums[i-1]) continue; //i>start ensures duplicate elements are no added when recursion is folding up
        subset[subsetSize]=nums[i]; //if i==start, the duplicate elements are added to subset for first time
        backtrack(stack,subset,subsetSize+1,nums,numsSize,i+1);
    }
}
void quicksort(int* array,int startIndex,int endIndex){
    if(startIndex>=endIndex){
        return;
    }
    int pivot=startIndex;
    int temp;
    for(int i=startIndex;i<=endIndex-1;i++){
        if(array[i]<=array[endIndex]){
            temp=array[i];
            array[i]=array[pivot];
            array[pivot]=temp;
            pivot++;
        }
    }
    temp=array[pivot];
    array[pivot]=array[endIndex];
    array[endIndex]=temp;
    quicksort(array,startIndex,pivot-1);
    quicksort(array,pivot+1,endIndex);
}
int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    Stack stack;
    stack.top=NULL;stack.size=0;
    int* subset=malloc(numsSize*sizeof(int));
    quicksort(nums,0,numsSize-1);
    backtrack(&stack,subset,0,nums,numsSize,0);
    *returnSize=stack.size;
    int** returnArray=malloc(*returnSize*sizeof(int*));
    *returnColumnSizes=malloc(*returnSize*sizeof(int));
    for(int i=0;i<*returnSize;i++){
        *(*returnColumnSizes+i)=(stack.top)->size;
        returnArray[i]=pop(&stack);
    }
    return returnArray;
}
