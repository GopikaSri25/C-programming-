int titleToNumber(char* columnTitle) {
    int a=0;
    for(int i=0;columnTitle[i]!='\0';i++){
    a=a*26+(columnTitle[i]-'A'+1);
    }
    return a;
}
