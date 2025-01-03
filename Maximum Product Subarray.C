int maxProduct(int* nums, int N){
    int result = nums[0];
    for(int i=1, MIN=result, MAX=result; i<N; i++){
        if(nums[i]<0){
            int save = MIN;
            MIN = MAX;
            MAX = save;
        }
        MAX *= nums[i];
        MIN *= nums[i]; 
        MAX = nums[i] >= MAX ? nums[i] : MAX ;
        MIN = nums[i] <= MIN ? nums[i] : MIN ;
        result = result >= MAX ? result : MAX;
    }
    return result;
}
