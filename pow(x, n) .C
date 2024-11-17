double myPow(double x, int n){
    double ans = 1;
    long n1 = n;
    if(n<0) 
        n1=-n1;
    int i = 0;
    while(n1 > 0)
    {
        if(n1 & 1L)
        {
            ans *= x;
            --n1;
        }
        else
        {
            x*=x;
            n1 /= 2;
        }
    }
    if(n<0)
        return 1.0/ans;
    return ans;
    
}
