#include <iostream>
#include <vector>
using namespace std;
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