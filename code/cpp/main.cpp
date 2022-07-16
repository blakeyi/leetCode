#include "common.h"
using namespace std;

/*
** 题目链接:https://leetcode.cn/problems/subsets/
** 题目简述:78. 子集
** 题目分类:dp
** 反思收获:
*/

class Solution78
{
  public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back(vector<int>());
        for (size_t i = 0; i < nums.size(); i++) {
            int len = ans.size();
            for (size_t j = 0; j < len; j++) {
                vector<int> temp = ans[j];
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};

int main() {
    Solution78 so;
    vector<int> input = {1, 3, 5};

    // vector<vector<int>> ans = {{1}, {1, 3, 5}, {5}};
    // for (auto i : ans) {
    //     cout << i.size();
    // }

    so.subsets(input);
    return 0;
}