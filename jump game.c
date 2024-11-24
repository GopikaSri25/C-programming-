bool canJump(int* nums, int numsSize){
    int i = 0;
    while ( i < numsSize - 1 ){
        int bestJump = 0;
        for (int j = 1; j <= nums[i]; j++){
            if (i + j == numsSize - 1) return true;
            if (j + nums[i+j] > bestJump + nums[i+bestJump]) {
                bestJump = j;
            }
        }
        if (bestJump == 0) return false;
        i += bestJump;
    }
    return true;
in
