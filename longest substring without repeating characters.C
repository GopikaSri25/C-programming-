
int lengthOfLongestSubstring(char *s) {
    int n = strlen(s); 
    int len = 0; .
    int l = 0; 
    int st[256]; 
    for (int i = 0; i < 256; i++) {
        st[i] = -1; 
    }

    for (int r = 0; r < n; r++) {
        if (st[s[r]] == -1) { 
            st[s[r]] = r;
            len = (len > r - l + 1) ? len : r - l + 1; 
        } else { 
            while (st[s[r]] != -1) { 
                st[s[l]] = -1; 
                l++; 
            }
            st[s[r]] = r;
        }
    }
    return len; 
}
