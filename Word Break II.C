/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAXANS 100000
void backTrack(char *s, int i, char **dict, int dsz, int curp, char **ans, int *ansLen) {
    static char curr[MAXANS];
    int j, dLen;
    if (s[i] == '\0') {
        ans[*ansLen] = strdup(curr);
        *ansLen += 1;
        return;
    }
    if (curp > 0) curr[curp++] = ' ';
    for (j = 0; j < dsz; ++j) {
        dLen = strlen(dict[j]);
        if (strncmp(s+i, dict[j], dLen)) continue;
        strcpy(curr+curp, dict[j]);
        backTrack(s, i+dLen, dict, dsz, curp+dLen, ans, ansLen);
    }
}
char** wordBreak(char* s, char** wordDict, int wordDictSize, int* returnSize) {
    char **ans = (char**) malloc(MAXANS * sizeof(char*));
    int ansLen = 0;
    backTrack(s, 0, wordDict, wordDictSize, 0, ans, &ansLen);
    *returnSize = ansLen;
    return ans;
}
