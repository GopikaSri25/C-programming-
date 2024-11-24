char pop(int k, unsigned char* llist, unsigned char* head) {
    int i = 1;
    char ret;
    if (k == 1) {
        ret = (char)llist[2 * (*head)];
        *head = llist[2 * (*head) + 1];
        return ret;
    }
    unsigned char prev = 255;
    unsigned char start = (unsigned char)(*head);

    while (i != k) {
        prev = start;
        start = llist[2 * start + 1];
        i++;
    }
    ret = (char)llist[2 * start];
    llist[2 * prev + 1] = llist[2 * start + 1];
    return ret;
}

int recurse(int n, int k, int s, char* ans, int* fact, unsigned char* llist, unsigned char* head) {
    if (n == s)
        return 0;
    int p = k / fact[n - s - 1];
    int d = k % fact[n - s - 1];

    if (d == 0) {
        char m = pop(p, llist, head);
        ans[s] = m;
        int i = 0;
        int j = s + 1;
        while (j != n) {
            ans[n - 1 - i] = llist[2 * (*head)];
            *head = llist[2 * (*head) + 1];
            i++;
            j++;
        }
        return 0;
    }

    else {
        char m = pop(p + 1, llist, head);
        ans[s] = m;
        recurse(n, d, s + 1, ans, fact, llist, head);
    }
    return 0;
}

char* getPermutation(int n, int k) {
    unsigned char llist[18] = {49, 1,  50, 2,  51, 3,  52, 4,  53,
                 5,  54, 6,  55, 7,  56, 8,  57, 255};
    unsigned char head = 0;
    int fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

    char* ans = (char*)malloc((n+1)*sizeof(char));
    ans[n] = '\0';
    recurse(n, k, 0, ans, fact, llist, &head);

    return ans;
}
