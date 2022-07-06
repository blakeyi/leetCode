#include <bits/stdc++.h>
using namespace std;

/*
** 题目链接:https://leetcode.cn/problems/trapping-rain-water/
** 题目简述:42. 接雨水
** 题目分类:双指针
** 解题思路:每个点能储存的雨水取决于其左右两边的最大值的最小值,注意可能为负数进行补偿
** 反思收获:
*/

class Solution42
{
  public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int ans = 0;
        while (left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if (leftMax < rightMax) {
                ans += leftMax - height[left];
                left++;
            } else {
                ans += rightMax - height[right];
                right--;
            }
        }
        return ans;
    }
};

int main() {
    Solution42 so;
    vector<int> nums = {4, 2, 0, 3, 2, 5};
    bool a = true;
    printf("%d", a);
    so.trap(nums);

    return 0;
}