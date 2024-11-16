int divide(int dividend, int divisor) {  
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX; 
    }
    int sign = (dividend > 0) == (divisor > 0) ? 1 : -1;
    long long absDividend = llabs((long long) dividend);
    long long absDivisor = llabs((long long) divisor);

    long long quotient = 0;
    while (absDividend >= absDivisor) {
        long long tempDivisor = absDivisor;
        long long multiple = 1;
        while (absDividend >= (tempDivisor << 1)) {
            tempDivisor <<= 1;
            multiple <<= 1;
        }
        absDividend -= tempDivisor;
        quotient += multiple;
    }
    return (int) (sign * quotient);
}
