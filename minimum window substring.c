char* minWindow(char* s, char* t) {
    int quota['z' + 1] = {0}, remaining = 0;
    while (*t) if (quota[*t++]++ == 0) remaining++;
    ptrdiff_t best = 99999;
    char *l = s, *L = s, *R;
    for (; *s; s++) {
        if (--quota[*s] == 0) remaining--;
        while (*l && quota[*l] < 0) quota[*l++]++;
        if (remaining == 0 && s - l < best) { best = s - l; L = l; R = s; }
    }
    *(best == 99999 ? L : R + 1) = 0;
    return L;
}
