void swap(int* x, int* y) {
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}
void sortColors(int* nums, int numsSize) {
    int len = numsSize;
    int maxi = INT_MIN;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (nums[j] < nums[i])
                swap(&nums[i], &nums[j]);
        }
    }
}
