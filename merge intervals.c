
int asscending(const void* nums1, const void* nums2){
    if(((int**)nums1)[0][0] == ((int**)nums2)[0][0]){
        return ((int**)nums1)[0][1] - ((int**)nums2)[0][1];
    }
    return ((int**)nums1)[0][0] - ((int**)nums2)[0][0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
*returnSize =0;
if(intervalsSize == 0){return NULL;}
qsort(intervals,intervalsSize,sizeof(intervals[0]),asscending);
int** return_array = (int**)malloc(sizeof(int*)*intervalsSize);
int* return_array_ele = NULL;
int trip_cond =0;

for(int idx =0 ;idx < intervalsSize; idx++){
    
    if(trip_cond == 0){
        return_array_ele = intervals[idx];
        trip_cond = 1;
        continue;
    }
    if(return_array_ele[0] <= intervals[idx][0] && return_array_ele[1] >= intervals[idx][0]){
        return_array_ele[1] = return_array_ele[1] > intervals[idx][1] ? return_array_ele[1] : intervals[idx][1];
    }
    else{
        return_array[(*returnSize)++] = return_array_ele;
        trip_cond =0;
        idx--;
    }
}

return_array[(*returnSize)++] = return_array_ele;
returnColumnSizes[0] = (int*)malloc(sizeof(int)*(*returnSize));
for(int idx =0 ; idx < (*returnSize); idx++){
    returnColumnSizes[0][idx] = 2;
}
return return_array;
}
