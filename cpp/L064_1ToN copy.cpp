#include<iostream>
#include<string>
#include<algorithm>
#include <vector>
#include<math.h>
using namespace std;

class Solution {
    int findMaxForm(vector<string> strs, int m, int n) {
        int strsNum = strs.length;
        int[][][] dp = new int[strsNum + 1][m + 1][n + 1];
		
        
        for (int i = 1; i <= strsNum; i++) {
            int[] cnt = count(strs[i - 1]);

            for (int j = 0; j <= m; j++) {
                for(int k = 0; k <= n; k++) {

                    if (cnt[0] > j || cnt[1] > k) {
                        dp[i][j][k] = dp[i - 1][j][k];
                    } else {
                        dp[i][j][k] = Math.max(dp[i - 1][j][k], dp[i - 1][j - cnt[0]][k - cnt[1]] + 1);
                    }
                }
            }
        }

        return dp[strsNum][m][n];
    }

    
    // cnt[0] = zeroNums, cnt[1] = oneNums
    int count(string str) {
        int[] cnt = new int[2];
        for (char c : str.toCharArray()) {
            cnt[c - '0']++;
        }
        return cnt;
    }
}
class Solution {
    int findMaxForm(vector<string> strs, int m, int n) {
        int strsNum = strs.length();
        int[][][] dp = new int[strsNum + 1][m + 1][n + 1];
		
        
        for (int i = 1; i <= strsNum; i++) {
            int[] cnt = count(strs[i - 1]);

            for (int j = 0; j <= m; j++) {
                for(int k = 0; k <= n; k++) {

                    if (cnt[0] > j || cnt[1] > k) {
                        dp[i][j][k] = dp[i - 1][j][k];
                    } else {
                        dp[i][j][k] = Math.max(dp[i - 1][j][k], dp[i - 1][j - cnt[0]][k - cnt[1]] + 1);
                    }
                }
            }
        }

        return dp[strsNum][m][n];
    }

    
    // cnt[0] = zeroNums, cnt[1] = oneNums
    int count(string str) {
        int[] cnt = new int[2];
        for (char c : str.toCharArray()) {
            cnt[c - '0']++;
        }
        return cnt;
    }
}

int main()
{
    Solution so;
    string
    so.findMaxForm()
}