 #define MAX_ELEMENT 10
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {

    int totalSubset = 1<<numsSize;
    int** aar = (int **)calloc(totalSubset, sizeof(int *));    
    *returnColumnSizes = malloc(totalSubset*sizeof(int));
    *returnSize = 0;

    for(int i=0; i<totalSubset; i++){
        aar[i] = (int *)malloc(numsSize*sizeof(int));
        *(*returnColumnSizes+i) = 0;
        int idx = 0;
        
        for(int k=0; k<numsSize; k++){
            if(i & (1<<k)){
                
                aar[i][idx++] = nums[k];
                *(*returnColumnSizes+i) +=1;                
            }
        }
        

    }

    *returnSize = totalSubset;
   
    return aar;   
}
