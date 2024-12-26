void computePalindromes(char* s, bool** dp, int n) {
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
        if (i + 1 < n) dp[i][i + 1] = (s[i] == s[i + 1]);
    }
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
        }
    }
}

void backtrack(int index, char* s, char** curr, int currSize, char**** result, int* resultSize, int** returnColumnSizes, bool** dp, int* resultCapacity) {
    int n = strlen(s);
    if (index >= n) {
        if (*resultSize >= *resultCapacity) {
            *resultCapacity *= 2;
            *result = (char***)realloc(*result, sizeof(char**) * (*resultCapacity));
            *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int) * (*resultCapacity));
        }
        (*result)[*resultSize] = (char**)malloc(sizeof(char*) * currSize);
        for (int i = 0; i < currSize; i++) {
            (*result)[*resultSize][i] = strdup(curr[i]);
        }
        (*returnColumnSizes)[*resultSize] = currSize;
        (*resultSize)++;
        return;
    }
    for (int i = index; i < n; i++) {
        if (dp[index][i]) {
            curr[currSize] = strndup(s + index, i - index + 1);
            backtrack(i + 1, s, curr, currSize + 1, result, resultSize, returnColumnSizes, dp, resultCapacity);
            free(curr[currSize]);
        }
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    int n = strlen(s);
    bool** dp = (bool**)malloc(sizeof(bool*) * n);
    for (int i = 0; i < n; i++) {
        dp[i] = (bool*)malloc(sizeof(bool) * n);
        memset(dp[i], false, sizeof(bool) * n);
    }
    computePalindromes(s, dp, n);

    int initialCapacity = 128; // Initial capacity to reduce the number of reallocations
    char*** result = (char***)malloc(sizeof(char**) * initialCapacity);
    *returnColumnSizes = (int*)malloc(sizeof(int) * initialCapacity);
    *returnSize = 0;

    char** t = (char**)malloc(sizeof(char*) * n);
    int resultCapacity = initialCapacity;

    backtrack(0, s, t, 0, &result, returnSize, returnColumnSizes, dp, &resultCapacity);

    for (int i = 0; i < n; i++) {
        free(dp[i]);
    }
    free(dp);
    free(t);

    return result;
}
