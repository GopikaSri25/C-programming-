void backtrack(int curr_row, int *col, int *p_diag, int *n_diag, int nqueens, int level, int *cnt)
{
    if (level == 0) {
        (*cnt)++;
        return ;
    }

    for (int j = 0; j < nqueens; j++) {
        if (col[j] == 0 && p_diag[curr_row + j] == 0 && n_diag[curr_row - j + nqueens - 1] == 0) {
            col[j] = 1;
            p_diag[curr_row + j] = 1;
            n_diag[curr_row - j + nqueens - 1] = 1;
            backtrack(curr_row + 1, col, p_diag, n_diag, nqueens, level - 1, cnt);
            col[j] = 0;
            p_diag[curr_row + j] = 0;
            n_diag[curr_row - j + nqueens - 1] = 0;
        }
    }
}

int totalNQueens(int n)
{
    int res = 0;
    int *col = calloc(n, sizeof(int));
    int *p_diag = calloc(2 * n - 1, sizeof(int));
    int *n_diag = calloc(2 * n - 1, sizeof(int));

    backtrack(0, col, p_diag, n_diag, n, n, &res);

    free(col);
    free(p_diag);
    free(n_diag);
    return res;
}
