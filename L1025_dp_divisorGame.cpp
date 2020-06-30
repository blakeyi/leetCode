#include <iostream>
#include <vector>
using namespace std;
bool divisorGame(int N) {
    /*
    1.分析：谁先到 N = 2,就可以赢，因为你再选一次1，就剩 N = 1,另一个人就没得选了
    2.区分N的初始情况，若为奇数，奇数的约数为奇数，相减为偶数，偶数的约数可奇可偶
    3.因为可以随便选数，N为偶数，一开始是alice选的，为了保证赢得话，她可以一直选1
    4.这样的话，bob选的时候就一直N是奇数，最终alice会到 N = 2，稳赢
    */
   if (N % 2 == 0) {
       return true;
   }
   return false;

}