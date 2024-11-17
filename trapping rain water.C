int max(int a, int b) { return (a > b) ? a : b; }
int trap(int* height, int heightSize) {
    int l = 0, r = heightSize - 1, lmax = INT_MIN, rmax = INT_MIN, ans = 0;
    while (l < r) {
        lmax = fmax(lmax, height[l]);
        rmax = fmax(rmax, height[r]);
        ans += (lmax < rmax) ? lmax - height[l++] : rmax - height[r--];
    }
    return ans;
}
