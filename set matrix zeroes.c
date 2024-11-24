void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int zero_x[200] = {0};
    int zero_y[200] = {0};
    int i, j;

    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < matrixColSize[0]; j++) {
            if (matrix[i][j] == 0) {
                zero_x[i] = 1;
                zero_y[j] = 1;
            }
        }
    }

    for (i = 0; i < matrixSize; i++) {
        if (zero_x[i] == 1) {
            for (j = 0; j < matrixColSize[0]; j++) matrix[i][j] = 0;
        }
    }

    for (j = 0; j < matrixColSize[0]; j++) {
        if (zero_y[j] == 1) {
            for (i = 0; i < matrixSize; i++) matrix[i][j] = 0;
        }
    }

}
