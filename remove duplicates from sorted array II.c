int removeDuplicates(int* nums, int numsSize){
    if(numsSize <= 1) return numsSize;
    int count=0;
    for(int i=0; i<numsSize-1; i++){
        if(nums[i] < nums[i+1]) nums[count++] = nums[i];
        else{
            nums[count++] = nums[count++] = nums[i];
            while(i<numsSize-1 && nums[i] >= nums[i+1]) i++;
        }
        if(i+1 == numsSize-1) nums[count++] = nums[i+1];
    }
    return count;
}
