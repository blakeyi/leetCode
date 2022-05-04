#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int> &nums)
{
    /*
    1.dp方法分析：
     1)确认状态：最后一步的状态是 前面有一个点j可以跳到最后一个点i，
        需要满足 nums[j] >= i - j ,即j点上能跳的最大距离大于等于i和j之间的距离
     2) 转移方程 ，可以设置一个数组vec，vec[i]表示是否能跳到当前i点，
     3) 初始状态和边界条件，vec[0]肯定是true，因为是开始点，不跳就行
     4) 计算顺序，在第二层循环的时候可以从最接近 i的点开始计算，不然容易超时
    */
    vector<bool> vec(nums.size());
    vec[0] = true;
    for (int i = 1; i < nums.size(); i++) {
        vec[i] = false;
        for (int j = 0; j < i; j++) {
            if (vec[j] && (nums[j]) >= (i - j)) {
                vec[i] = true;
                break;
            }
        }
    }
    return vec.back();
}

int main()
{
    vector<int> vec;
    int num[] = {3, 2, 1, 0, 4};
    for (int i = 0; i < 5; i++) {
        vec.push_back(num[i]);
    }
    cout << canJump(vec);
    return 0;
}