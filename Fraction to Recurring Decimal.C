
typedef long long i64;

void next(i64* r, i64* n, i64 b) {
    *n = (*r*10) / b;
    *r = (*r*10) % b;
}

char * fractionToDecimal(int numerator, int denominator){
    char* ret = malloc(20000);
    char* p = ret;
    i64 a = numerator;
    i64 b = denominator;
    i64 r1, r2;
    i64 n1, n2;
    int i;
    int point = 0;
       
    a = labs(a);
    b = labs(b);
    
    r1 = r2 = a%b;

    next(&r1, &n1, b);

    next(&r2, &n2, b);
    next(&r2, &n2, b);

    // has cycle
    while (r1 != r2) {
        next(&r1, &n1, b);

        next(&r2, &n2, b);
        next(&r2, &n2, b);
    }

    int start = 0;
    int len = 1;

    r1 = a%b;
    
    // cycle start
    while (r1 != r2) {
        next(&r1, &n1, b);
        next(&r2, &n2, b);
        start ++;
    }

    // cycle len
    next(&r1, &n1, b);
    while (r1 != r2) {
        next(&r1, &n1, b);
        len ++;
    }

    if ((i64)numerator*(i64)denominator < 0) {
        sprintf(ret, "-%lld", a/b);
    } else {
        sprintf(ret, "%lld", a/b);
    }
    p += strlen(ret);
    
    r1 = a%b;
    next(&r1, &n1, b);
    for (i = 0; i < start; i++) {
        if (!point) {
            *p++ = '.'; point = 1;
        }

        *p++ = n1 + '0';
        next(&r1, &n1, b);
    }
    if (len > 1 || n1 != 0) {
        if (!point) {
            *p++ = '.'; point = 1;
        }

        *p++= '(';
        for (i = 0; i < len; i++) {
            *p++ = n1 + '0';
            next(&r1, &n1, b);
        }
        *p++= ')';
    }
    *p++= 0;
    return ret;
}
