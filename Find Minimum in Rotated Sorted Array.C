int findMin(int* nums, int numsSize) {
    int min = INT_MAX;
    int low = 0, high = numsSize - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[low] <= nums[mid]) {
            min = (nums[low] < min) ? nums[low] : min;
            low = mid + 1;
        } else {
            min = (nums[mid] < min) ? nums[mid] : min;
            high = mid - 1;
        }
    }
    return min;
}
