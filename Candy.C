int candy(int* ratings, int ratingsSize) {
    
    int candies[ratingsSize];
    int i = 1;
    candies[0] = 0;
    for (  i; i < ratingsSize; i++) {
        candies[i] = (candies[i - 1] + 1) * (*(ratings + i - 1) < *(ratings + i));
        
    }
    int sum = ratingsSize + candies[--i];
    i-=1;
    for (i; i > -1; i--) {
        if ((*(ratings + i + 1) < *(ratings + i)) && candies[i+1] + 1 > candies[i]) {
            candies[i] = candies[i+1] + 1;
        }
        sum += candies[i];
    }
    return sum;
}
