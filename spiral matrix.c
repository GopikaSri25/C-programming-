/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool checklevel(int i, int j, int n, int level) {
    if (level > i && (n - 1 - level) < i) return false;
    if (level > j && (n - 1 - level) < j) return false;
    return true;
}

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int colSize = *matrixColSize;
    int size = matrixSize * colSize;
    int* result = (int*)malloc(size * sizeof(int));
    int index = 0, dindex = 0;
    int i = 0, j = 0,next_i = 0,next_j = 0;
    int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while (index < size) {
        result[index++] = matrix[i][j];
        matrix[i][j] = INT_MAX;
        next_i = i + direction[dindex][0];
        next_j = j + direction[dindex][1];
        if (next_i < 0 || next_i > matrixSize - 1 || next_j < 0 || next_j > colSize - 1 || matrix[next_i][next_j] == INT_MAX){ 
            dindex = (dindex + 1) % 4;
        }
        i += direction[dindex][0];
        j += direction[dindex][1];
    }
    *returnSize = index;
    return result;
}
