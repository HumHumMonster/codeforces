/*
1157C2 div3(构造).cpp

给出一个长度为n的数组

要求从数组的左端或者右端选取数
要求当前取的数要比上次取的要大
问最多能取多少次，取法如何

例如
5
1 2 4 3 2

4
LRRR

其实就是个小模拟
如果不一样就取小的那边
如果一样就看哪边取的多点

*/


#include <stdio.h>
#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <iterator>
#include <set>
using namespace std ;
#define LL long long
#define INF 0x3f3f3f3f
const double PI = acos(-1.0) ;
const double eps = 1e-8 ;

inline int _max(int a , int b){return a > b ? a : b ;}
inline int _min(int a , int b){return a < b ? a : b ;}
inline int _abs(int a){return a > 0 ? a : -a ;}
inline double _max(double a , double b){return a > b ? a : b ;}
inline double _min(double a , double b){return a < b ? a : b ;}
inline double _fabs(double a){return a > 0 ? a : -a ;}
inline LL _max(LL a , LL b){return a > b ? a : b ;}
inline LL _min(LL a , LL b){return a < b ? a : b ;}
inline LL _labs(LL a){return a > 0 ? a : -a ;}

int sgn(double x)   //判断正负，正为1，零为0，负为-1
{
    if (_fabs(x) < eps) return 0 ;
    else if (x < 0) return -1 ;
    else return 1 ;
}


/***************************************************************/

const int MAXN = 2e5 + 10 ;
string str ;
int n ;
int num[MAXN] ;
int main ()
{
    scanf ("%d" , &n) ;
    for (int i = 1 ; i <= n ; ++i)
        scanf ("%d" , &num[i]) ;
    int l = 1 , r = n ;
    int now = 0 ;
    while (1)
    {
        if (num[l] <= now && num[r] <= now)
            break ;
        if (num[l] < num[r])
        {
            if (num[l] > now)
            {
                now = num[l] ;
                str += 'L' ;
                ++l ;
                if (l > r)
                    break ;
            }
            else if (num[r] > now)
            {
                now = num[r] ;
                str += 'R' ;
                --r ;
                if (l > r)
                    break ;
            }
        }
        else if (num[r] < num[l])
        {
            if (num[r] > now)
            {
                now = num[r] ;
                --r ;
                str += 'R' ;
                if (l > r)
                    break ;
            }
            else if (num[l] > now)
            {
                now = num[l] ;
                str += 'L' ;
                ++l ;
                if (l > r)
                    break ;
            }
        }
        else
        {
            int nowl = 0 ;
            if (num[l] > now)
            {
                nowl = 1 ;
                for (int i = l + 1 ; i < r ; ++i)
                {
                    if (num[i] > num[i - 1])
                        ++nowl ;
                    else
                        break ;
                }
            }
            int nowr = 0 ;
            if (num[r] > now)
            {
                nowr = 1 ;
                for (int i = r - 1 ; i > l ; --i)
                {
                    if (num[i] > num[i + 1])
                        ++nowr ;
                    else
                        break ;
                }
            }
            if (nowl >= nowr)
            {
                while (nowl--)
                {
                    str += 'L' ;
                }
            }
            else
            {
                while (nowr--)
                {
                    str += 'R' ;
                }
            }
            break ;
        }
    }
    printf ("%d\n" , str.size()) ;
    cout << str ;
}
