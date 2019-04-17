/*
*1154F div3(完全dp、前缀和).cpp

给出n个物品,m种优惠,k(代表需要购买物品的数量)
接着给出每种物品的价格
然后给m行,每行两个整数x , y,
代表你当前购买 x 个物品,那么这 x 个物品中最便宜的 y 个免费

于是我们可以把物品价格排序一下,
求一个前缀和
然后用完全dp就可以做了
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

int n , m , k ;
const int maxn = 2e5 + 10 ;
LL dp[2005] ;
LL num[maxn] ;
LL fuli[maxn] ;
LL ans[maxn] ;
LL a , b ;
LL qq ;
int main ()
{
    scanf ("%d%d%d" , &n , &m , &k) ;
    for (int i = 1 ; i <= n ; ++i)
        scanf ("%lld" , &num[i]) ;
    while (m--)
    {
        scanf ("%lld%lld" , &a , &b) ;
        fuli[a] = _max(fuli[a] , b) ;
    }
    sort (num + 1 , num + 1 + n) ;
    for (int i = 1 ; i <= n ; ++i)
        ans[i] = ans[i - 1] + num[i] ;
    for (int i = 1 ; i <= k ; ++i)
    {
        dp[i] = dp[i - 1] + num[i] ;
        for (int j = 0 ; j < i ; ++j)
        {
            int p = i - j ;
            p = fuli[p] ;
            int now = dp[j] + ans[i] - ans[j + p] ;
            if (now < dp[i])
                dp[i] = now ;
        }
    }
//    for (int i = 1 ; i <= k ; ++i)
//    {
//        printf ("i = %d   dp = %d\n" , i , dp[i]) ;
//    }
    printf ("%lld" , dp[k]) ;
}
