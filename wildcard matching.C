bool isMatch(char* s, char* p) {
    char *backtrack = 0;
    char *backtrackP = 0;
start:
    if (*p == 0) {
        if (*s == 0) {
            return true;
        }
        if (backtrack == 0) {
            return false;
        }
        backtrack += strlen(s);
        s = backtrack;
        p = backtrackP;
        goto start;
    } else if (*p == '?') {
        if (*s == 0) {
            return false;
        }
        p++;
        s++;
        goto start;
    } else if (*p == '*') {
        p++;
        if (*s == 0) {
            backtrack = 0;
        } else {
            backtrack = s;
        }
        backtrackP = p;
        goto start;
    } else if (*p != *s) {
        if (*s == 0 || backtrack == 0) {
            return false;
        }
        backtrack++;
        s = backtrack;
        p = backtrackP;
        goto start;
    } else {
        p++;
        s++;
        goto start;
    }
}
