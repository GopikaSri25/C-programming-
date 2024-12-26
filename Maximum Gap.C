int com_pare(const void *a , const void *b)
{
    return *(int *)a - *(int *)b;
}

int maximumGap(int* nums, int numsSize) {

if(numsSize < 2)
{
    return 0;
}
if(numsSize == 2)
{
    return abs(nums[0]-nums[1]);
} 

qsort(nums , numsSize , sizeof(int ) , com_pare);

int jvrc = 0 ;

for(int i = 0 ; i < numsSize-1; i++)
{
    if(abs(nums[i]-nums[i+1]) > jvrc)
    {
        jvrc = abs(nums[i]-nums[i+1]);
    }
}
return jvrc;

}
