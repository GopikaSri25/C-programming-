void check(int *nums,int ans,int cur, int numsSize,int *result,int target)
{
    if(cur == numsSize)
    {
        if(ans == target)
            (*result)++;
        return;
    }
    check(nums,ans+nums[cur],cur+1,numsSize,result,target);
    check(nums,ans-nums[cur],cur+1,numsSize,result,target);
}
int findTargetSumWays(int* nums, int numsSize, int target) {
    int result=0;
    check(nums,0,0,numsSize,&result,target);
    return result;
}
