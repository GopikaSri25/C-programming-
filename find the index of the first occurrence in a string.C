int strStr(char* haystack, char* needle) {
    int haystack_size = strlen(haystack);
    int needle_size = strlen(needle);
    int result = -1;
    int i = 0;  
    int j = 0;  

    while (i < (haystack_size) && j < needle_size) {
        if (haystack[i] == needle[j]) {
            i++;
            j++;
        }
        else {
            i = i - j + 1;
            j = 0;
        }
    }

    return result = (j == needle_size) ? (i - needle_size) : -1;
}
