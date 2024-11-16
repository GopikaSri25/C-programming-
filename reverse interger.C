int reverse(int x){
    long long int pal=0;
    while(x!=0)
    {
        pal=pal*10+x%10;
        x/=10;
    }
    if(pal<INT_MIN || pal>INT_MAX)
    {
        return 0;
    }
    else
        return pal;
}
