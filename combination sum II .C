void combination2(int **res, int *returnSize, int** returnColumnSizes, int *combination, int combinationSize, int *candidates, int target, int index, int candidatesSize);
void merge(int *candidates, int l, int m, int r);
void mergeSort(int *candidates, int l, int r);

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    mergeSort(candidates, 0, candidatesSize - 1);
    int **result = (int **)malloc(1000 * sizeof(int *)); 
    *returnSize = 0;
    *returnColumnSizes = (int *)malloc(1000 * sizeof(int));
    int *combination = (int *)malloc(candidatesSize * sizeof(int)); 

    combination2(result, returnSize, returnColumnSizes, combination, 0, candidates, target, 0, candidatesSize);
    
    free(combination);
    return result;
}
void combination2(int **res, int *returnSize, int** returnColumnSizes, int *combination, int combinationSize, int *candidates, int target, int index, int candidatesSize) {
    if (target == 0) {
        res[*returnSize] = (int *)malloc(combinationSize * sizeof(int)); 
        for (int i = 0; i < combinationSize; i++) {
            res[*returnSize][i] = combination[i]; 
        }
        (*returnColumnSizes)[*returnSize] = combinationSize; 
        (*returnSize)++;
        return;
    }
    for (int i = index; i < candidatesSize && target >= candidates[i]; ++i) {
        if (i == index || candidates[i] != candidates[i - 1]) {
            combination[combinationSize] = candidates[i]; 
            combination2(res, returnSize, returnColumnSizes, combination, combinationSize + 1, candidates, target - candidates[i], i + 1, candidatesSize);
        }
    }
}

void merge(int *candidates, int l, int m, int r) {
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = candidates[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = candidates[m + 1 + j]; 
  
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            candidates[k] = L[i]; 
            i++; 
        } 
        else { 
            candidates[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) { 
        candidates[k] = L[i]; 
        i++; 
        k++; 
    } 
   
    while (j < n2) { 
        candidates[k] = R[j]; 
        j++; 
        k++; 
    } 
}

void mergeSort(int *candidates, int l, int r) {
    if (l < r) { 
        int m = l + (r - l) / 2; 
  
        mergeSort(candidates, l, m); 
        mergeSort(candidates, m + 1, r); 
  
        merge(candidates, l, m, r); 
    } 
}
