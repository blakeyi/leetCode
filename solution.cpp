#include<bits/stdc++.h>
using namespace std;
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}//构造函数
};
 
class Solution_add {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);//头结点
        ListNode* L = head;//移动指针
        int val1 = 0, val2 = 0, c = 0;
        while (l1 != NULL || l2 != NULL)
        {
            if (l1 == NULL) val1 = 0;
            else val1 = l1->val;
            if (l2 == NULL) val2 = 0;
            else val2 = l2->val;
            ListNode* p = new ListNode((val1 + val2 + c) % 10);
            if ((val1 + val2 + c) > 9) c = 1;
            else c = 0;
            L->next = p;
            L = p;
            if (l1 != NULL)l1 = l1->next;
            if (l2 != NULL)l2 = l2->next;
        }
        if (c)
        {
            ListNode* p = new ListNode(1);
            L->next = p;
        }
        return head->next;

    }

};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int flag[256]; int max = 0, len = 0;
        int start = 0, end = 0;
        memset(flag, -1, sizeof(int)*256);
        for (int i = 0; i < s.length(); i++) {
            if (flag[s[i]] != -1&& flag[s[i]]>=start) {//没有相同元素
                start = flag[s[i]] + 1;
                len = end - start;
            }
            flag[s[i]] = i;
            len++;
            end++;
            if (len > max) max = len;
        }
        return max;
    }
};

class Solution_findMedianSortedArrays {
public:
    int findKthElm(vector<int>& nums1, vector<int>& nums2, int k) {
        assert(1 <= k && k <= nums1.size() + nums2.size());
        int le = max(0, int(k - nums2.size())), ri = min(k, int(nums1.size()));
        while (le < ri) {
            int m = le + (ri - le) / 2;
            if (nums2[k - m - 1] > nums1[m]) le = m + 1;
            else ri = m;
        }//循环结束时的位置le即为所求位置，第k小即为max(nums1[le-1]),nums2[k-le-1])，但是由于le可以为0、k,所以
        //le-1或者k-le-1可能不存在所以下面单独判断下
        int nums1LeftMax = le == 0 ? INT_MIN : nums1[le - 1];
        int nums2LeftMax = le == k ? INT_MIN : nums2[k - le - 1];
        return max(nums1LeftMax, nums2LeftMax);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        if (n & 1) {//两个数组长度和为奇数
            return findKthElm(nums1, nums2, (n >> 1) + 1);
        }
        else {//为偶数
            return (findKthElm(nums1, nums2, n >> 1) + findKthElm(nums1, nums2, (n >> 1) + 1)) / 2.0;
        }
    }
};


class Solution_gameOfLife {
public:
    void gameOfLife(vector<vector<int>>& board) {
        /*int dx[] = { -1,  0,  1, -1, 1, -1, 0, 1 };
        int dy[] = { -1, -1, -1,  0, 0,  1, 1, 1 };*/

        int dx[] = { -1,  0,  1,  1, 1,  0, -1, -1 };
        int dy[] = { -1, -1, -1,  0, 1,  1, 1, 0 };

        for (int i = 0; i < board.size(); i++) {//i代表行
            for (int j = 0; j < board[0].size(); j++) {//j代表列
                int sum = 0;
                for (int k = 0; k < 8; k++) {//先计算周围细胞情况
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
                        sum += (board[nx][ny] & 1); // 只累加最低位,因为后面会更新第二个bit位
                    }
                }
                if (board[i][j] == 1) {
                    if (sum == 2 || sum == 3) {
                        board[i][j] |= 2;  // 使用第二个bit标记是否存活
                    }
                }
                else {
                    if (sum == 3) {
                        board[i][j] |= 2; // 使用第二个bit标记是否存活
                    }
                }
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                board[i][j] >>= 1; //右移一位，用第二bit覆盖第一个bit。
            }
        }
    }
};


int main()
{
    vector<vector<int>> board = { {0,1,0},{0,0,1},{1,1,1},{0,0,0} };
    Solution_gameOfLife so;
    so.gameOfLife(board);
    return 0;
}