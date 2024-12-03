char ** restoreIpAddresses(char * s, int* returnSize){
  const size_t len = strlen(s);
  char** ret = NULL;
  size_t capacity = 0;
  *returnSize = 0;
  for (int a = 1;  (a <= 3) && (a + 2 < len) && (1 == a || '0' != s[0]) && (a < 3 || 0 > memcmp(s, "256", 3)); ++a) {
    for (int b = a + 1; (b <= a + 3) && (b + 1 < len) && (a + 1 == b || '0' != s[a]) && (b < a + 3 || 0 > memcmp(s + a, "256", 3)); ++b) {
      for (int c = b + 1; (c <= b + 3) && (c < len) && (b + 1 == c || '0' != s[b]) && (c < b + 3 || 0 > memcmp(s + b, "256", 3)); ++c) {
        if ((c + 3 >= len) && (c + 1 == len || '0' != s[c]) && (len < c + 3 || 0 > memcmp(s + c, "256", 3))) {
          if (*returnSize >= capacity) {
            capacity = (capacity) ? capacity * 2 : 1;
            ret = (char**) realloc(ret, sizeof(char*) * capacity);
          }
          char* dest = (char*) malloc(len + 4);
          memcpy(dest        , s    , a    );
          dest[a] = '.';
          memcpy(dest + a + 1, s + a, b - a);
          dest[b + 1] = '.';
          memcpy(dest + b + 2, s + b, c - b);
          dest[c + 2] = '.';
          memcpy(dest + c + 3, s + c, len - c);
          dest[len + 3] = '\0';
          ret[(*returnSize)++] = dest;
        }
      }
    }
  }
  return ret;
}
