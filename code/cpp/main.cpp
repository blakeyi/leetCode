#include <bits/stdc++.h>
using namespace std;

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

int main() {
    vector<int> nums = {1, 3, 4, 7};
    auto iter = lower_bound(nums.begin(), nums.end(), 2, greater<int>());
    cout << *iter;
    return 0;
}