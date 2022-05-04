#include <iostream>
#include <vector>
using namespace std;
string longestPalindrome(string s)
{
    /*
   1.dp[i][j]为true表示s[i][j]子串为回文串，false则不是
   2.i = j时,很显然dp[i][j]为true
   3.i + 1 = j时，如果s[i] = s[j],则为true
   4.j - i > 2时，判断dp[i + 1][j - 1]和s[i] = s[j]的情况
   5.时间复杂度为 o(n2),空间复杂度为o(n)
   */
    int n = s.size();
    int j;
    string ans;
    vector<vector<bool>> dp(n, vector<bool>(n));
    for (int k = 0; k < s.size(); k++) {
        for (int i = 0; i + k < s.size(); i++) {
            j = i + k;
            if (k == 0) { // i = j 时相当于子串只有一个
                dp[i][j] = true;
            } else if (k == 1) { // i,j相隔1
                dp[i][j] = (s[i] == s[j]);
            } else { //去掉头尾的子串 + 头尾是否相等
                dp[i][j] = (dp[i + 1][j - 1] && (s[i] == s[j]));
            }
            // 更新长度
            if (dp[i][j] && (k + 1) > ans.size()) {
                ans = s.substr(i, k + 1);
            }
        }
    }
    return ans;
}

string longestPalindrome1(string s)
{
    /*
   1.dp[i][j]为true表示s[i][j]子串为回文串，false则不是
   2.i = j时,很显然dp[i][j]为true
   3.i + 1 = j时，如果s[i] = s[j],则为true
   4.j - i > 2时，判断dp[i + 1][j - 1]和s[i] = s[j]的情况
   5.时间复杂度为 o(n2),空间复杂度为o(n)
   */
    
    return ans;
}
int main()
{
    string str = "a";
    cout << longestPalindrome(str);
    return 0;
}