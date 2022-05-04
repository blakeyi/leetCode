#include <iostream>
#include <vector>
using namespace std;

int coinChange(vector<int> &coins, int amount)
{
    vector<int> vec(amount + 1); // 申请数组
    vec[0] = 0;
    for (int i = 1; i < amount + 1; i++) {
        vec[i] = INT32_MAX;
        for (int j = 0; j < coins.size(); j++) {
            if (i >= coins[j] && vec[i - coins[j]] != INT32_MAX) {
                vec[i] = min(vec[i - coins[j]] + 1, vec[i]);
            }
        }
    }
    if (vec[amount] == INT32_MAX) {
        return -1;
    }
    return vec[amount];
}
int main()
{
    vector<int> coins;
    int num[3] = {1, 2, 5};
    for (int i = 0; i < 3; i++) {
        coins.push_back(num[i]);
    }
    coinChange(coins, 11);

    return 0;
}