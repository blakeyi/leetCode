#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int m, int n)
{
    vector<vector<int>> vec(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0) {
                vec[i][j] = 1;
            } else {
                vec[i][j] = vec[i - 1][j] + vec[i][j - 1];
            }
        }
    }
    return vec[m - 1][n - 1];
}

int main()
{
    int i;
    return 0;

}