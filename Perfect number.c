bool checkPerfectNumber(int num) {
    if (num % 2 == 1)
        return false;
    int sum = 0;
    for (int i = 1; i < num / 2 + 1; i++)
    {
        if (num % i == 0)
        {
            sum += i;
        }
    }
    if (num == sum)
        return true;
    else
        return false;
}
