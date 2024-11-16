int cmp(const void* a, const void* b) { 
    return *((int*)a) - *((int*)b);
}
int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int ans = INT_MAX, op = 0;
    for (int i = 0; i < numsSize - 2; ++i) {
        int j = i + 1, k = numsSize - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (fabs(sum - target) < ans) {
                ans = fabs(sum - target);
                op = sum;
                if (sum == target)
                    return op;
            }
            (sum > target) ? k-- : j++;
        }
    }
    return op;
}
