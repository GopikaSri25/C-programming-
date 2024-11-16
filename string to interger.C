int myAtoi(char * s){
    int i, len = strlen(s);
    int val = 0;
    int sign = 1, check = 0;
    
    for (i=0;i<len;i++) {
        if (check == 0 && (s[i] == '+' || s[i] == '-')) {
            check = 1;
            sign = s[i] == '+' ? 1 : -1;
            continue;
        }

        if (check == 0 && s[i] == ' ') {
            continue;
        }

        if (s[i] >= '0' && s[i] <= '9') {
            check = 1;

            if (val > 214748364 || (val == 214748364 && s[i] > '7')) {
                if (sign == 1) {
                    return 2147483647;
                }
                else {
                    return -2147483648;
                }
            }

            val = val * 10 + (s[i] - '0');
        }
        else {
            break;
        }
    }

    return sign * val;
}
