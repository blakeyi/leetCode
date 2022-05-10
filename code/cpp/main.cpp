#include <bits/stdc++.h>
using namespace std;

/*
** 题目链接:https://leetcode.cn/problems/partition-equal-subset-sum/
** 题目简述:分割等和子集
** 题目分类:动态规划(01背包问题)
** 解题思路:就是从n个数里找m个数使得其和为总和的一半
用二维bool数组,dp[i][j]表示,从遍历到第i个数时,其和为j的可能性是否为真,因此dp[i][0]都为true,因为可以全不选,就为0
** 反思收获:
*/

class Solution416
{
  public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2)
            return false;
        int target = sum / 2, n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = true;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = nums[i - 1]; j <= target; ++j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
            }
        }
        return dp[n][target];
    }
};

int main() {
    Solution416 so;
    vector<int> nums = {1, 5, 10, 6};
    bool a = true;
    printf("%d", a);
    so.canPartition(nums);

    return 0;
}