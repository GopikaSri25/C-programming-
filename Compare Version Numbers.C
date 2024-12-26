int compareVersion(char* version1, char* version2) {
    int compare = 0;
    char* v1[500] = {0}; 
    char* v2[500] = {0}; 
    int v1_size = 0;
    int v2_size = 0;

    char* token = strtok(version1, ".");
    while (token != NULL) {
        v1[v1_size++] = token;
        token = strtok(NULL, ".");
    }

    token = strtok(version2, ".");
    while (token != NULL) {
        v2[v2_size++] = token;
        token = strtok(NULL, ".");
    }

    int max_len = v1_size > v2_size ? v1_size : v2_size;

    for (int i = 0; i < max_len; i++) {
        int revision1 = i < v1_size ? atoi(v1[i]) : 0;
        int revision2 = i < v2_size ? atoi(v2[i]) : 0;

        if (revision1 < revision2) {
            compare = -1;
            break;
        } else if (revision1 > revision2) {
            compare = 1;
            break;
        }
    }

    return compare;
}
