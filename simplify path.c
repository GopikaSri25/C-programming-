char* simplifyPath(char* path) {
    int len = strlen(path);
    char *stk = (char*) malloc ((len+1)*sizeof(sizeof(char))); 
    int top = 0;
    stk[0] = path[0]; 

    for(int i=1; i < len; i++){
        if(path[i]=='/' && (stk[top]=='/' || path[i+1]=='\0' || top==0))
            continue;
        if(path[i-1] == '/' && path[i] == '.'  && path[i+1] == '.' && (path[i+2] == '/' || path[i+2] == '\0')){
            if(i != 1 && top != 0)
            while(top >= 0 && stk[top] != '/')
                top--;
            i+=2;
        }
        else if(path[i-1] == '/' && path[i] == '.'  && (path[i+1] == '/' || path[i+1] == '\0')){
            if(i != 1 && top != 0) 
                top--;
        }
        else 
            stk[++top] = path[i];
        
        stk[top+1] = '\0';
    }
    if(top >0 && stk[top]=='/')
        top--;
        
    stk[top+1] = '\0';  
    return stk; 
}
