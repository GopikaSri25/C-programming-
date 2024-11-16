
int longestValidParentheses(char * s){
    int len = strlen(s);
    int* map = (int*)malloc(sizeof(int) * (len * 2 + 1));
    
    for (int i = 0; i < (len * 2 + 1); i++) {
        map[i] = (i == len ? 0 : -1);
    }

    int depth = 0;
    int best = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            depth += 1;
        } else if (s[i] == ')') {
            map[len + depth] = -1; 
            depth -= 1;
        }

        if (map[len + depth] != -1) {
            int candidate = (i + 1) - map[len + depth];
            best = candidate > best ? candidate : best;
        } else {
            map[len + depth] = i + 1;
        }
    }

    return best;
}
