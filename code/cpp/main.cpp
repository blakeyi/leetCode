#include "common.h"
using namespace std;

/*
** 题目链接:https://leetcode.cn/problems/rotate-image/
** 题目简述:48. 旋转图像
** 题目分类:顺时针旋转90度即先左对角线对称,然后左右对称
** 反思收获:
*/

class Solution461
{
  public:
    void rotate(vector<vector<int>>& matrix) {
        symmetryDiaLeft(matrix);
        symmetryCenterLeft(matrix);
    }

    // 按照左对角线对称
    void symmetryDiaLeft(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (size_t i = 0; i < n; i++) {
            for (size_t j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    // 按照右对角线对称-暂时未实现
    void symmetryDiaRight(vector<vector<int>>& matrix) {
        int n = matrix.size();
    }

    // 按照左右对称
    void symmetryCenterLeft(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < n / 2; j++) {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }

    // 按照上下对称
    void symmetryCenterTop(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (size_t i = 0; i < n / 2; i++) {
            for (size_t j = 0; j < n; j++) {
                swap(matrix[i][j], matrix[n - i - 1][j]);
            }
        }
    }
};

int main() {
    return 0;
}