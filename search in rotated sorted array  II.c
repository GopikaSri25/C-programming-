bool search(int* nums, int numsSize, int target) {
    int t=0,flag=0;
    for(int i=0;i<numsSize-1;i++)
    {
        t++;
        if(nums[i]>nums[i+1])
        {
            break;
        }
        if(i==numsSize-2)
            t=0;
    }
    printf("%d",t);
    int l=0,r=numsSize-1,mid=0,realmid=0;
    while(l<=r)
    {
        mid=(l+r)/2;
        realmid=(mid+t)%numsSize;
        if(nums[realmid]==target)
            break;
        else if(nums[realmid]>target)
            r=mid-1;
        else
             l=mid+1;
    }
    if(nums[realmid]==target)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
