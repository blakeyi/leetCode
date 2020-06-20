#include<iostream>
#include<string>
#include<algorithm>
#include <vector>
#include<math.h>
using namespace std;
int str2int(string str)
{

}
void recur(string str)
{
    if(str.length() == 1) {
        return;
    } else {
        recur(str.substr(1,str.length()));
        string temp;
        temp = str.substr(0,2); 
    }

}
class Solution {
public:
    int translateNum(int num) {

    }
};
int main()
{

    string str = "123";
    vector<string> vec;
    vec.push_back(str);
    cout << str2int(str);

    
}