#define MAX(a, b) ((a) > (b) ? (a) : (b))

int longest(char *s, int left, int right, int **dp)
{
    int max = 0, len;

    if (left == right) {
        return 1;
    }
    else if (left > right) {
        return 0;
    }

    if (dp[left][right] != -1) {
        return dp[left][right];
    }

    
    if (s[left] == s[right]) {
        len = 2 + longest(s, left + 1, right - 1, dp);
        max = MAX(max, len);
    }

    
    len = longest(s, left + 1, right, dp);
    max = MAX(max, len);

   
    len = longest(s, left, right - 1, dp);
    max = MAX(max, len);

    dp[left][right] = max;

    return max;
}

int longestPalindromeSubseq(char* s) {

    int ans, len = strlen(s) + 1, **dp = (int **)malloc(sizeof(int *) * len);

    for (int i = 0; i < len; i++) {
        dp[i] = (int *)malloc(sizeof(int) * len);

        for (int j = 0; j < len; j++) {
            dp[i][j] = -1;
        }
    }

    ans = longest(s, 0, len - 1, dp);

    for (int i = 0; i < len; i++) {
        free(dp[i]);
    }

    free(dp);

  
    
    return ans;
}
