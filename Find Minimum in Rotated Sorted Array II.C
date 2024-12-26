int findMin(int* nums, int numsSize) {
    int min=INT_MIN;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]<min||min==INT_MIN)
        {
            min=nums[i];
        }
    }
    return min;
}
