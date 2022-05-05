#include <bits/stdc++.h>
using namespace std;

/*
** 题目链接:https://leetcode-cn.com/problems/house-robber/?utm_source=LCUS&utm_medium=ip_redirect&utm_campaign=transfer2china
** 题目简述:打家劫舍
** 题目分类:动态规划
** 解题思路: dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]), 取决于当前的这个拿不拿
** 反思收获:
*/

class Solution198
{
  public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[1] = nums[0];
        for (size_t i = 2; i <= n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        return dp[n];
    }
};

int main() {
    Solution70 so;
    so.climbStairs(5);
    cout << so.climbStairs(5);
}