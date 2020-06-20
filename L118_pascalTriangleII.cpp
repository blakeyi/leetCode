#include <iostream>
#include <vector>
using namespace std;
/*
1.杨辉三角：
2.GetPascalNum()主要是用递归方法，求指定行列的值
3.原理：f(x, y) = f(x-1, y-1) + f(x-1, y) 而f(1,y) = f(x, x) = 1, x,y从1开始

4.getRow()获取每一行的值，每次利用上一行的值来计算下一行的值，注意：
5.相加时最好从末尾向前加，不然会覆盖出错
*/
vector<int> getRow(int rowIndex)
{
    vector<int> vec;
    vec.push_back(1);
    for (int i = 0; i < rowIndex; i++) {
        vec.push_back(1);
        for (int j = vec.size() - 2; j > 0; j--) {
            vec[j] = vec[j] + vec[j - 1];
        }
    }
    return vec;
}

int GetPascalNum(int row, int col)
{
    if (col == 1 || col == row) {
        return 1;
    } else {
        return GetPascalNum(row - 1, col - 1) + GetPascalNum(row - 1, col);
    }
}