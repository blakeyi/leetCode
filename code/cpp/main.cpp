#include "common.h"
using namespace std;

/*
** 题目链接:https://leetcode.cn/problems/merge-two-binary-trees/
** 题目简述:617. 合并二叉树
** 题目分类:深度优先
** 反思收获:
*/

class Solution461
{
  public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) {
            return root2;
        }
        if (root2 == nullptr) {
            return root1;
        }
        TreeNode* merged = new TreeNode(root1->val + root2->val);
        merged->left = mergeTrees(root1->left, root2->left);
        merged->right = mergeTrees(root1->right, root2->right);
        return merged;
    }
};

int main() {
    return 0;
}