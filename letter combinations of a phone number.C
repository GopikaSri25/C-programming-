
 void backtrack(char*, char*, int, char**, char**, int*);
char** letterCombinations(char* digits, int* returnSize) {
    if(strlen(digits) == 0){
        *returnSize = 0;
        return NULL;
    }
    char* map[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    int numRows = 1, numCols = strlen(digits);
    for(int i = 0; i < strlen(digits); i++){
        if(digits[i] == '7' || digits[i] == '9')
            numRows *= 4;
        else
            numRows *= 3;
    }

    *returnSize = numRows;
    char** ans = (char**)malloc(sizeof(char*) * numRows);
    for(int i = 0; i < numRows; i++){
        ans[i] = (char*)malloc(sizeof(char) * (numCols + 1));
        ans[i][0] = '\0';
    }
    
    char combination[numCols + 1];
    combination[0] = '\0';
    int ansIdx = 0;
    backtrack(combination, digits, 0, map, ans, &ansIdx);
    return ans;
}

void backtrack(char* combination, char* digits, int i, char** map, char** ans, int* ansIdx){
    
    if(i >= strlen(digits)){
        strcpy(ans[(*ansIdx)++], combination);
        return;
    }
    
    char* letters = map[digits[i] - '2'];

    for(int j = 0; j < strlen(letters); j++){
        char newCombination[strlen(combination) + 2];
        strcpy(newCombination, combination);
        newCombination[strlen(combination)] = letters[j];   
        newCombination[strlen(combination) + 1] = '\0'; 
        backtrack(newCombination, digits, i+1, map, ans, ansIdx);
    }
}
