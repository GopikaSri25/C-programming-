int findPeakElement(int* nums, int numsSize) {
    int n = numsSize;
    if (n == 1)
        return 0;
    if (nums[0] > nums[1])
        return 0;
    if (nums[n - 1] > nums[n - 2])
        return n - 1;

    int l = 1;
    int r = n - 2;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;

        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
            ans = mid;
            break;
        }

        if (nums[mid] > nums[mid - 1])
            l = mid + 1;
        else
            r = mid - 1;
    }
    return ans;
}
