int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    int m = obstacleGridSize;
    int n = *obstacleGridColSize;

    int dp[m][n];

    for (int i = 0; i < m; i++) {
        if (obstacleGrid[i][0] == 1) {
            while (i < m) {
                dp[i][0] = 0;
                i++;
            }
        } else {
            dp[i][0] = 1;
        }
    }
    for (int j = 0; j < n; j++) {
        if (obstacleGrid[0][j] == 1) {
            while (j < n) {
                dp[0][j] = 0;
                j++;
            }
        } else {
            dp[0][j] = 1;
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    return dp[m - 1][n - 1];
}
