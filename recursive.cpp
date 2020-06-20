#include <iostream>
#include <vector>
using namespace std;
struct NODE
{
    int value;
    NODE *next;
};

void printReverse(const NODE *node)
{
    if (!node) { // 字符串最后一个为\0,z作为退出条件
        return;
    }
    printReverse(node->next);
    printf("%d -> ", node->value);
}

void print(const NODE *node)
{
    while (node) {
        printf("%d -> ", node->value);
    }
}

void printReverse(const char *str)
{
    if (!*str) { // 字符串最后一个为\0,z作为退出条件
        return;
    }
    printReverse(str + 1);
    putchar(*str);
}

int pascaNum(int row, int col)
{
    if (col == 1 || col == row) {
        return 1;
    } else {
        return pascaNum(row - 1, col - 1) + pascaNum(row - 1, col);
    }
}
vector<int> getRow(int rowIndex)
{
    vector<int> vec;
    vec.push_back(1);
    for (int i = 0; i < rowIndex; i++) {
        vec.push_back(1);
        for (int j = vec.size()- 2; j > 0; j--) {
            vec[j] = vec[j] + vec[j - 1];
        }
        
    }
    return vec;
}
vector<vector<int>> generateTriangle(int numRows)
{
    vector<int> vec1;
    vector<vector<int>> vec;
    for (int i = 0; i < numRows + 1; i++)
    {
        vec1 = getRow(i);
        vec.push_back(vec1);
    }
    return vec;
}

int main()
{
    vector<int> vec1;
    vector<vector<int>> vec = generateTriangle(5);
    vec1 = getRow(4);
    return 0;
}