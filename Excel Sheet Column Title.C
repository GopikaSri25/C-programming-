int calculateLength(int columnNumber) {
    int length = 0;
    while (columnNumber > 0) {
        columnNumber = (columnNumber - 1) / 26;
        length++;
    }
    return length;
}
char* convertToTitle(int columnNumber) {
    int len = calculateLength(columnNumber);
    char* res = (char*)malloc(sizeof(char) * (len + 1));
    res[len] = '\0';
    for (int i = len - 1; i >= 0; i--) {
        char toAppened = ((columnNumber - 1) % 26) + 65;
        res[i] = toAppened;
        columnNumber = (columnNumber - 1) / 26;
    }
    return res;
}
