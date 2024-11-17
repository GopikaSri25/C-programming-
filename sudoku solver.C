int free1(char** board, int* row, int* col) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                *row = i; *col = j; return 1;
            }
        }
    }
    return 0;
}

int safe(char** board, int row, int col, int num) {
    char n = num + '0';
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == n || board[i][col] == n)
            return 0;
    }
    int startRow = (row / 3) * 3, startCol = (col / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == n)
                return 0;
        }
    }
    return 1;
}

int help(char** board) {
    int row, col;
    if (!free1(board, &row, &col)) return 1; 
    for (int num = 1; num <= 9; num++) {
        if (safe(board, row, col, num)) {
            board[row][col] = num + '0';
            if (help(board)) return 1; 
            board[row][col] = '.'; 
        }
    }
    return 0; // No solution
}

void solveSudoku(char** board, int boardSize, int* boardColSize) {
    help(board);
}
