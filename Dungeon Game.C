int calculateMinimumHP(int** dungeon, int dungeonSize, int* dungeonColSize){
    int m = dungeonSize;
    int n = *dungeonColSize ;
    int** dp = malloc(m * sizeof(int*)) ;
    for(int i = 0; i < m; i++){
        dp[i] = malloc(n * sizeof(int)) ;
    }
    for(int i = m-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            if(i == m-1 && j == n-1)
                dp[i][j] = 1 ;
            else if(i == m-1)
                dp[i][j] = dp[i][j+1] - dungeon[i][j+1] ;
            else if(j == n-1)
                dp[i][j] = dp[i+1][j] - dungeon[i+1][j] ;
            else
                dp[i][j] = fmin(dp[i][j+1] - dungeon[i][j+1] , dp[i+1][j] - dungeon[i+1][j]) ;
            dp[i][j] = fmax(1, dp[i][j]) ;
        }
    }
    int ret = dp[0][0] - dungeon[0][0] ;
    for(int i = 0; i < m; i++)
        free(dp[i]) ;
    free(dp) ;
    return fmax(ret , 1) ;
}
