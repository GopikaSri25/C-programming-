int maxProfit(int* prices, int pricesSize){
    int profit = 0, min = prices[0], temp;
    for(int i=1; i<pricesSize; i++){
        if(prices[i]<min) min = prices[i];
        temp = prices[i] - min;
        if(temp > profit) profit = temp;
    }
    return profit;
}
