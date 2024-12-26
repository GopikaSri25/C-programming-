#include <limits.h>

int maxProfit(int* prices, int pricesSize) {
    int firstBuy, firstProfit, secondBuy, secondProfit;

    // init vars
    firstBuy = INT_MAX; secondBuy = INT_MAX;
    firstProfit = 0; secondProfit = 0;

    // traverse prices array - the final result will be secondProfit
    for (int i = 0; i < pricesSize; i++)
    {
        firstBuy = (prices[i] < firstBuy) ? prices[i] : firstBuy;
        firstProfit = (prices[i] - firstBuy > firstProfit) ? prices[i] - firstBuy : firstProfit;
        secondBuy = (prices[i] - firstProfit < secondBuy) ? prices[i] - firstProfit : secondBuy;
        secondProfit = (prices[i] - secondBuy > secondProfit) ? prices[i] - secondBuy : secondProfit;
    }

    return secondProfit;
}
