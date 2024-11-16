char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";
    
    for (int i = 0; i < strsSize - 1; i++) {
        for (int j = i + 1; j < strsSize; j++) {
            if (strlen(strs[i]) > strlen(strs[j])) {
                char* temp = strs[i];
                strs[i] = strs[j];
                strs[j] = temp;
            }
        }
    }
    
    char* prefix = (char*)malloc(strlen(strs[0]) + 1);
    int len = 0;
    
    for (int i = 0; i < strlen(strs[0]); i++) {
        for (int j = 1; j < strsSize; j++) {
            if (strs[j][i] != strs[0][i]) {
                prefix[len] = '\0';
                return prefix;
            }
        }
        prefix[len++] = strs[0][i];
    }
    
    prefix[len] = '\0';
    return prefix;
}
