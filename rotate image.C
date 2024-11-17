void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
    for(int i = 0; i < matrixSize; i++)
    {
        for(int j = i + 1; j < matrixColSize[i]; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    int w = matrixColSize[0];
    for(int i = 0; i < matrixSize; i++)
    {
        for(int j = 0; j < matrixColSize[i] / 2; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][w - 1 - j];
            matrix[i][w - 1 - j] = temp;
        }
    }
}
