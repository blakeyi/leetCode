#include "common.h"
using namespace std;

/*
** 题目链接:https://leetcode-cn.com/problems/max-area-of-island/
** 题目简述:695. 岛屿的最大面积
** 题目分类:深度优先搜索
** 反思收获:
** 三种写法:
** 1.用栈模拟递归,首先遍历二维数组,
*对于值为1的点开始搜索,用栈存储,把当前点的上下左右四个方向上的点遍历一遍,如果为1,则入栈,遍历完后再从栈顶取元素重新开始,直到栈中无元素结束
*/

class Solution695
{
  public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = m ? grid[0].size() : 0;
        int maxSize = 0;
        vector<int> direction{-1, 0, 1, 0, -1};
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;  // 防止重复搜索
                    stack<pair<int, int>> island;
                    island.push({i, j});
                    int areaSize = 1;
                    while (!island.empty()) {
                        auto [l, r] = island.top();
                        island.pop();
                        for (size_t k = 0; k < 4; k++) {
                            int x = l + direction[k];
                            int y = r + direction[k + 1];
                            if (x >= 0 && x < m && y >= 0 && y < n &&
                                grid[x][y]) {
                                areaSize++;
                                grid[x][y] = 0;  // 重点
                                island.push({x, y});
                            }
                        }
                    }
                    maxSize = max(maxSize, areaSize);
                }
            }
        }
        return maxSize;
    }
};

int main() {
    Solution695 so;
    vector<vector<int>> input = {{1, 0, 1, 1, 0, 1, 0, 1},
                                 {1, 0, 1, 1, 0, 1, 1, 1},
                                 {0, 0, 0, 0, 0, 0, 0, 1}};

    so.maxAreaOfIsland(input);
    return 0;
}