
/*
** 题目链接:https://leetcode-cn.com/problems/climbing-stairs/?utm_source=LCUS&utm_medium=ip_redirect&utm_campaign=transfer2china
** 题目简述:爬楼梯, 一次只能怕一阶或者两阶
** 题目分类:动态规划
** 解题思路:状态转移方程, dp[i] = i, i <= 2; dp[i] = dp[i - 1] + dp[i - 2], n > 2
** 反思收获:注意边界条件处理
*/

class Solution70 {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        vector<int> dp(n + 1, 1); // 初始化为1,可以取消dp单独赋值,然后i从2开始
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