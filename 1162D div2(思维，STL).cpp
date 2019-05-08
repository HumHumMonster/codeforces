/*
1162D div2(思维，STL).cpp

从别人的代码里总能学到一些东西

给一个圆盘，上面有n个刻度和m条线条，
问能不能选装小于n个刻度后，旋转的图像和初始相同

把所有n的因数拿去旋转就好了

这里用到一个unordered_set，用哈市实现的
可以把两个整数放到一个LL中再插入unordered_set
*/

#include <unordered_map>
#include <unordered_set>
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

int n , m ;
unordered_set <LL> S ;
const int MAXN = 2e5 + 10 ;
LL a[MAXN] , b[MAXN] , now ;

int main ()
{
    scanf ("%d%d" , &n , &m) ;
    for (int i = 1 ; i <= m ; ++i)
    {
        scanf ("%lld%lld" , &a[i] , &b[i]) ;
        a[i] %= n ;
        b[i] %= n ;
        if (a[i] < b[i])
            swap(a[i] , b[i]) ;
        now = (a[i] << 32) | b[i] ;
        //printf ("a = %lld  b = %lld  now = %lld\n" , a[i] , b[i] , now) ;
        S.insert(now) ;
    }
    for (int i = 1 ; i < n ; ++i)
    {
        if (n % i) continue ;
        bool flag = true ;
        for (int j = 1 ; j <= m ; ++j)
        {
            LL nowx = a[j] + i ;
            LL nowy = b[j] + i ;
            nowx %= n ;
            nowy %= n ;
            if (nowx < nowy)
                swap(nowx , nowy) ;
            //printf ("a = %lld  b = %lld  now = %lld\n" ,nowx , nowy , now) ;
            nowx = (nowx << 32) | nowy ;
            if (!S.count(nowx))
            {
                flag = false ;
                break ;
            }
        }
        if (flag)
        {
            printf ("YES") ;
            return 0 ;
        }
    }
    printf ("NO") ;
}
