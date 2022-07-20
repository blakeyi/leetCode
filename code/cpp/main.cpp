#include "common.h"
using namespace std;

/*
** 题目链接:https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/
** 题目简述:114. 二叉树展开为链表
** 题目分类:链表和二叉树
** 反思收获:
*/

class Solution114
{
  public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> list;
        preOrder(root, list);
        if (list.size() <= 1) {
            return;
        }
        for (size_t i = 0; i < list.size() - 1; i++) {
            list[i]->left = nullptr;
            list[i]->right = list[i + 1];
        }
        return;
    }
    void preOrder(TreeNode* root, vector<TreeNode*>& list) {
        if (root == nullptr) {
            return;
        }
        list.push_back(root);
        preOrder(root->left, list);
        preOrder(root->right, list);
    }
};

int main() {
    Solution114 so;
    vector<int> input = {1, 3, 5, INT_MAX, INT_MAX, INT_MAX, INT_MAX};

    // vector<vector<int>> ans = {{1}, {1, 3, 5}, {5}};
    // for (auto i : ans) {
    //     cout << i.size();
    // }

    TreeNode* root = CreatTree(input);
    so.flatten(root);
    return 0;
}