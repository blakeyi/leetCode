#ifndef _COMMON_H_
#define _COMMON_H_

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// 层序遍历建树
/*
        1
     2     3
   nl nl  nl nl
nl 用INT_MAX代替
*/
TreeNode* CreatTree(vector<int> nums) {
    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode*> tQueue;
    tQueue.push(root);
    int n = nums.size(), i = 1;
    while (!tQueue.empty() && i < n) {
        TreeNode* p = tQueue.front();
        TreeNode *left, *right;
        tQueue.pop();
        if (nums[i] != INT_MAX) {
            left = new TreeNode(nums[i]);
        } else {
            left = nullptr;
        }
        i++;
        if (nums[i] != INT_MAX) {
            right = new TreeNode(nums[i]);
        } else {
            right = nullptr;
        }
        i++;
        if (p) {
            p->left = left;
            p->right = right;
            tQueue.push(left);
            tQueue.push(right);
        }
    }
    return root;
}

ListNode* CreatList(vector<int> nums) {
    ListNode* head = new ListNode(nums[0]);
    ListNode* phead = head;
    for (int i = 1; i < nums.size(); ++i) {
        ListNode* node = new ListNode(nums[i]);
        phead->next = node;
        phead = node;
    }
    return head;
}

#endif