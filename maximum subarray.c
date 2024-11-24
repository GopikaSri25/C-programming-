int maxSubArray(int* nums, int numsSize) {
    int maxSum = INT_MIN, curr = 0;
    for (int i = 0; i < numsSize; i++) {
        curr += nums[i];
        maxSum = curr > maxSum ? curr : maxSum;
        if (curr < 0)
            curr = 0;
    }
    return maxSum;
}
