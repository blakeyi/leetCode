#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int maxProfit(vector<int> &prices)
{
    /*
    1.动态规划
    2.用minNum记录今天之前的最小股价值
    3.用maxProfit记录今天卖出可以获得的最大利润
    */
    if(prices.size() == 0) {
        return 0;
    }
    int minNum = prices[0], maxProfit = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] < minNum) {
            minNum = prices[i];
        } else {
            maxProfit = max(prices[i] - minNum, maxProfit);
        }
    }
   return maxProfit;
}

int main() {}