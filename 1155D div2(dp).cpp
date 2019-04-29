/*
1155D div2(dp).cpp

这个题出得是真的有趣
给一个 n 一个 k
接下来给一个长度为 n 的数组
求最大子段和
你可以让区间内的一个子段的所有数乘上 k

动态规划
这大概就是紫名守门题了把

思路：
dp1[i]：以a[i]结尾的最大子段和
dp2[i]：a[i]被乘以x且以a[i]结尾的最大子段和
dp3[i]：a[i]没有被乘以x，但在a[i]之前有一个区间被乘以x，以a[i]结尾且包含该区间的最大子段和

答案就是这些dp中最大的那个
递推公式在代码中
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
const int MAXN = 3e5 + 10 ;

LL num[MAXN] ;
LL dp1[MAXN] , dp2[MAXN] , dp3[MAXN] ;
int n , k ;
LL res = 0 ;
int main ()
{
    scanf ("%d%d" , &n , &k) ;
    for (int i = 1 ; i <= n ; ++i)
    {
        scanf ("%lld" , &num[i]) ;
        dp1[i] = num[i] + _max(dp1[i - 1] , 0LL) ;
        res = _max(res , dp1[i]) ;
    }
    for (int i = 1 ; i <= n ; ++i)
    {
        dp2[i] = num[i] * k + _max(_max(dp2[i - 1] , dp1[i - 1]) , 0LL) ;
        res = _max(res , dp2[i]) ;
    }
    for (int i = 1 ; i <= n ; ++i)
    {
        dp3[i] = num[i] + _max(_max(dp2[i - 1] , dp3[i - 1]) , 0LL) ;
        res = _max(res , dp3[i]) ;
    }
    printf ("%lld" , res) ;
}
