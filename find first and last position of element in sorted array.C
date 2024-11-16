int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int l = 0, r = numsSize, mid;    
    
    int* ret = malloc(sizeof(int) * 2);
    (*returnSize) = 2;
    
    while (l < r){
        mid = (l + r) >> 1;
        if (nums[mid] > target)
            r = mid;
        else
            l = mid + 1;
    }
    
    ret[1] = r - 1;
    l = 0; 
    
    while (l < r){
        mid = (l + r) >> 1;
        if (nums[mid] < target)
            l = mid + 1;
        else
            r = mid;
    }
    
    ret[0] = l;
    
    if (ret[0] > ret[1]){
        ret[0] = -1;
        ret[1] = -1;
    }
    
    return ret;
}
