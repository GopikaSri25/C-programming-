int search(int* nums, int numsSize, int target) {
    int start = 0;
    int end = numsSize-1;

    while(start < end){
        int middle = (start + end)/2;
        if(nums[middle] == target)
            return middle;
        
        if(nums[middle] > nums[start] && nums[middle] > nums[end]){
           
            
            if(target < nums[middle] && target <= nums[end] || target > nums[middle])
                start = middle;
            else
                end = middle;
        }
        
        else if(nums[middle] < nums[start] && nums[middle] < nums[end]){
            
            if(target > nums[middle] && target >= nums[start] || target < nums[middle])
                end = middle;
            else
                start = middle;
        }
        
        else if(nums[middle] > nums[start] && nums[middle] < nums[end]){
            if(target < nums[middle])
                end = middle;
            else
                start = middle;
        }
        
        else
            start = end;
    }

    return nums[start] == target ? start : -1;
}
