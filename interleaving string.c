
bool isInterleave(char* s1, char* s2, char* s3) {
    int m = strlen(s1);
    int n = strlen(s2);
    if (m + n != strlen(s3))
        return false;

    bool* dp = (bool*)malloc((n + 1) * sizeof(bool));
    memset(dp, false, (n + 1) * sizeof(bool));

    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 && j == 0)
                dp[j] = true;
            else if (i == 0)
                dp[j] = dp[j - 1] && s2[j - 1] == s3[j - 1];
            else if (j == 0)
                dp[j] = dp[j] && s1[i - 1] == s3[i - 1];
            else
                dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) ||
                        (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
        }
    }

    bool result = dp[n];
    free(dp);  // Free the allocated memory

    return result;
}
