
#include <bits/stdc++.h>
using namespace std;

/*
** 题目链接:https://leetcode-cn.com/problems/climbing-stairs/?utm_source=LCUS&utm_medium=ip_redirect&utm_campaign=transfer2china
** 题目简述:爬楼梯, 一次只能怕一阶或者两阶
** 题目分类:动态规划
** 解题思路:状态转移方程, dp[i] = i, i <= 2; dp[i] = dp[i - 1] + dp[i - 2], n >
*2
** 反思收获:注意边界条件处理
*/

class Solution70
{
  public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        vector<int> dp(n + 1, 1);  // 初始化为1,可以取消dp单独赋值,然后i从2开始
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
    // 优化空间复杂度,dp[i]只与前两个相关
    int climbStairs1(int n) {
        if (n <= 2) {
            return n;
        }
        int pre1 = 1, pre2 = 2, cur;
        for (int i = 3; i <= n; ++i) {
            cur = pre1 + pre2;
            pre1 = pre2;
            pre2 = cur;
        }
        return cur;
    }
};

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

/*
**
题目链接:https://leetcode-cn.com/problems/longest-increasing-subsequence/?utm_source=LCUS&utm_medium=ip_redirect&utm_campaign=transfer2china
** 题目简述:最长递增子序列
** 题目分类:动态规划
** 解题思路:
解法1: 由于不是连续的,对于当前的nums[i],
需要向前遍历[0,i-1]的所有元素,如果nums[i] > nums[j],
则比较dp[i]和dp[j]+1的大小,至于为什么要比较,是因为dp[i]可能会一直变
解法2:解法1的时间间复杂度为O(n^2),dp来动态更新最长的序列,如果是大于dp中最大的,则直接插入队尾,如果不是则利用low_bound找到合适的位置插入

** 反思收获:
*/

class Solution300
{
  public:
    int lengthOfLIS(vector<int>& nums) {
        int maxLen = 0, n = nums.size();
        if (n <= 1) {
            return n;
        }
        vector<int> dp(n, 1);
        for (size_t i = 1; i < n; i++) {
            for (size_t j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
    int lengthOfLIS1(vector<int>& nums) {
        int maxLen = 0, n = nums.size();
        if (n <= 1) {
            return n;
        }
        vector<int> dp;
        dp.push_back(nums[0]);
        for (size_t i = 1; i < n; i++) {
            if (dp.back() < nums[i]) {
                dp.push_back(nums[i]);
            } else {
                auto iter = lower_bound(dp.begin(), dp.end(), nums[i]);
                *iter = nums[i];
            }
        }
        return dp.size();
    }
};