/*
1140A div2(模拟)

给出数组长度为n

你在看书，看书需要线索，如果你的线索大于i，你就可以读第i本书
如果不大于，你就需要等一天才能读这本书
看书顺序必须从1~i
你读过第i本书，你就拥有第i本书的线索。
问需要几天

*/


#include <stdio.h>
#include <iostream>
#include <map>
#include <algorithm>
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

const int maxn = 1e4 + 10 ;
int n ;
int num[maxn] ;
int res[maxn] ;
int main ()
{
    scanf ("%d" , &n) ;
    for (int i = 1 ; i <= n ; ++i)
    {
        scanf ("%d" , &num[i]) ;
    }
    int r = num[1] ;
    res[1] = 1 ;
    for (int i = 2 ; i <= n ; ++i)
    {
        if (i <= r)
        {
            res[i] = res[i - 1] ;
            if (num[i] > r)
                r = num[i] ;
        }
        else
        {
            res[i] = res[i - 1] + 1 ;
            r = num[i] ;
        }
    }
    printf("%d" , res[n]) ;
}
