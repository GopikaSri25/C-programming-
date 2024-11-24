int** generateMatrix(int n, int* returnSize, int** returnColumnSizes)
{
    *returnSize = n;
    *returnColumnSizes = malloc(sizeof(int) * n);
    int **res = malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = n;
        res[i] = malloc(sizeof(int) * n);
    }
    
    int top = 0;
    int bot = n - 1;
    int left = 0;
    int right = n - 1;
    
    int j = 1;
    while (j <= n * n) {
        for (int i = left; i <= right; i++, j++)
            res[top][i] = j;
        top++;

        for (int i = top; i <= bot; i++, j++)
            res[i][right] = j;
        right--;

        for (int i = right; i >= left; i--, j++)
            res[bot][i] = j;
        bot--;

        for (int i = bot; i >= top; i--, j++)
            res[i][left] = j;
        left++;
    }

    return res;
}
