int lengthOfLastWord(char* s) {
    int len = strlen(s);
    int max = 0;
    int i = len - 1;
    while(s[i] == ' ') {
        --i;
    }
    for(i; i >= 0; --i) {
        if(s[i] == ' ') {
            break;
        }
        ++max;
    }
    return max;
}   
