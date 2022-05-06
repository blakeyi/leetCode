#include <bits/stdc++.h>
using namespace std;

/*
** 题目链接:https://leetcode-cn.com/problems/minimum-path-sum/
** 题目简述:最短路径
** 题目分类:动态规划
** 解题思路: dp[i][j] = min(dp[i-1][j], dp[i][j-1]) +
*grid[i][j],只有两个方向可以到当前点
** 反思收获:
*/

class Solution64
{
  public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                } else if (i == 0) {
                    dp[i][j] = dp[i][j - 1] + grid[i][j];
                } else if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + grid[i][j];
                } else {
                    dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
    // 空间压缩, 用一行数据来记录,比如在第i行时,dp[j]代表原来的 dp[i][j-1];
    // dp[i-1]代表原来的dp[i-1][j]
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n, 0);
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[j] = grid[i][j];
                } else if (i == 0) {
                    dp[j] = dp[j] + grid[i][j];
                } else if (j == 0) {
                    dp[j] = dp[j - 1] + grid[i][j];
                } else {
                    dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
                }
            }
        }
        return dp[n - 1];
    }
};

int main() {
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    Solution64 so;
    cout << so.minPathSum(grid);
}