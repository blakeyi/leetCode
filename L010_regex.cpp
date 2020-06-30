#include <iostream>
#include <vector>
using namespace std;

bool isMatch(string s, string p)
{
    if (!s.size() || !p.size()) {
        return false;
    }
    if (s.size() != p.size() &&
        p.find('.') == p.npos && // 长度不相等，且p中不含 * 和 .
        p.find('*') == p.npos) {
        return false;
    }
    for (int i = 0, j = 0;i < p.size() && j < s.size();) { //用i,j指示当前字符串位置,i对应规则串,j对应源串
        if (p[i] == '.') {
            if(p[i + 1] == '*') {
                if(p.size() == 2) { // 如果只是.* ,则适配所有字符串
                    return true;
                }
                if((i + 2) < p.size()) { //*后面还有值，需要与s匹配，如果找不到，则false
                    int flag = false;
                    while(j < s.size()) {
                        if (p[i + 2] == s[j++] || p[i + 2] == '.') { //如果可以找到
                            i += 3;
                            flag = true;
                            if(i >= p.size() && j < s.size()) { // p[i]为'.'的时候，i超出范围了，但j还有，就是数目对不上了
                                return false;
                             }
                            if(j >= s.size() && i < p.size()) { // p[i]为'.'的时候，j超出范围了，但i还有，就是数目对不上了
                                return false;
                            }
                            break;
                        }
                    }
                    if (!flag) { // 没找到跳出循环的
                        return false;  
                    }
                       
                }
            }
            i++;
            j++;
            if(i >= p.size() && j < s.size()) { // p[i]为'.'的时候，i超出范围了，但j还有，就是数目对不上了
                return false;
            }
        } else {
            if (p[i] != s[j] && p[i + 1] != '*') { // 当前位置不相等，且规则串后面不是 *
                return false;
            } else if (p[i] == s[j] ) { // 当前相等
                if (p[i + 1] == '*') { // 如果xiandeng当前相等，则需要移动最后一个不相等的位置，需要考虑是否舍去这个位置
                    while (i < p.size() && j < (s.size())) {
                        if ((j + 1) < s.size() && p[i] == s[j + 1]) { //确保j+1不会越界，越界说明j为最后一个了
                            if(p[i+2] != s[j+1] && p[i+3] == '*') {
                                i += 4;
                            } else {
                                j++;
                            }
                                
                        } else {
                            if ((j + 1) >= s.size() && (i + 2) < s.size() ) { //当前j是最后一个元素,而 *后面还有值

                            }
                            j++;
                            i += 2;
                            break;
                        }
                    }
                } else { //不相等就直接忽略跳过
                    j++;
                    i++;
                }
            } else if (p[i] != s[j]) { // 当前不相等，但是后面是*。这种情况规则只是 规则串后移
                i += 2;
                if(i >= p.size() && j < s.size()) { // p[i]为'.'的时候，i超出范围了，但j还有，就是数目对不上了
                return false;
            }
            } else {
                i++;
                j++;
            }
        }
        if((i >= p.size() && j < s.size()) || (j >= s.size() && i < p.size()) ) { // p[i]为'.'的时候，i超出范围了，但j还有，就是数目对不上了
            if (p[i] == s.back() && (j >= s.size() && i < p.size()) ) { // a*a 匹配 aaa情况
                return true;
            }
            if(j >= s.size()) {
                while(p[i + 1] == '*') { // ab* 匹配 a
                    i += 2;
                }
                if(p[i] != p.back()) {
                    return true;
                } else {
                     return false;
                }    
            }
            return false; 
        }          
    }
    return true;
}
int main()
{
    string s, p;
    s = "a";
    p = ".*..a*";
    // s = "a";
    // p = "ab*"; 
    // s = "aaa";
    // p = "ab*a*c*a";
    cout << isMatch(s, p);
    return 0;
}