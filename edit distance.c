
int minDistance(char* word1, char* word2) {
    int n = strlen(word1);
    int m = strlen(word2);
    
    int rows = n + 1;
    int cols = m + 1;
    
    int** map_of_results = (int**) malloc(rows * sizeof(int*));
    for (int row_ctr = 0; row_ctr < rows; row_ctr++) { 
        map_of_results[row_ctr] = (int*)malloc(cols * sizeof(int));     
    }

    map_of_results[n][m] = 0;

    for (int i = n; i >= 0; i--) map_of_results[i][m] = (n - i);
    
    for (int j = m; j >= 0; j--) map_of_results[n][j] = (m - j);
    
    int ins_cost, del_cost, rep_cost, min;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            del_cost = map_of_results[i + 1][j] + 1;
            ins_cost = map_of_results[i][j + 1] + 1;
            
            rep_cost = map_of_results[i + 1][j + 1] + (word1[i]!=word2[j]);
            
            min = del_cost;
            if (ins_cost < min) min = ins_cost;
            if (rep_cost < min) min = rep_cost;

            map_of_results[i][j] = min;
        }
    }
    int res = map_of_results[0][0];
   
    for (int ptr = 0; ptr < rows; ptr++) free(map_of_results[ptr]);
    free(map_of_results);
    
    return res;
}
