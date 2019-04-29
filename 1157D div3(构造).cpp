/*

1157D div3(构造).cpp

给出一个 n , 一个 k
要求输出一个长度为 k 的数组
数组满足
1、和为 n
2、num[i] < num[i + 1]
3、num[i] * 2 <= num[i + 1]


呃呃呃，这场div3打的并不好
可做的前五题中，E和D都没做出来
D题算是一个构造题
先做一个递增数组，并且每个位置与相邻位置的差都为 1
然后从剩下的都加到最后一个上
从最后开始，如果不满足num[i] * 2 <= num[i + 1]，就把这两个值重新分配
最后看一下第一个值和第二个值可不可以就好
感觉像极了瞎搞，也许数据比较水把

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

LL n , k ;
LL p ;
const int MAXN = 1e5 + 10 ;

LL num[MAXN] ;

int main ()
{
    scanf ("%lld%lld" , &n , &k) ;
    p = (2 * n + k - k * k) / 2 / k ;
    //printf ("%lld" , p) ;
    if (p == 0)
    {
        printf ("NO") ;
        return 0 ;
    }
    n -= (p + p + k - 1) * k / 2 ;
    //printf ("n = %lld\n" , n) ;
    for (int i = 1 ; i <= k ; ++i)
    {
        num[i] = p + i - 1 ;
        //printf ("i = %d  num = %lld\n" , i , num[i]) ;
    }
    num[k] += n ;
    for (int i = k ; i >= 2 ; --i)
    {
        if (num[i] > 2 * num[i - 1])
        {
            LL now = (num[i] + num[i - 1]) ;
            if (now % 2)
                num[i] = now / 2 + 1 , num[i - 1] = now / 2 ;
            else
                num[i] = now / 2 + 1 , num[i - 1] = now / 2 - 1 ;
        }
        else
            break ;
    }
    if (num[1] * 2 < num[2])
    {
        printf ("NO") ;
        return 0 ;
    }
    printf ("YES\n") ;
    for (int i = 1 ; i <= k ; ++i)
        printf ("%lld " , num[i]) ;
}
