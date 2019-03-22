/*
1139C div2(并查集、快速幂)

给出一颗树，有n个节点
树上的边可能是黑的可能是红的
1为黑，0为红
如果一个序列包括k个节点
从第一个节点到最后一个节点都用最短路走过
能够经黑色边，说明序列是好的序列
问有多少个好的序列

这题取模最后要特判一下！
*/


#include <stdio.h>
#include <iostream>
#include <map>
#include <algorithm>
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

const int MOD = 1e9 + 7 ;

const int maxn = 2e5 + 10 ;

LL n , k ;
int fa[maxn] ;
LL num[maxn] ;
int find_fa(int x)
{
    if (x == fa[x])
        return x ;
    return fa[x] = find_fa(fa[x]) ;
}

void unit_fa(int a , int b)
{
    num[a] += num[b] ;
    fa[b] = a ;
}

//快速乘法
long long quick_mul(long long a , long long b , long long m)
{
    long long ans = 0 ;
    while (b)
    {
        if (b & 1)
            ans = (ans + a) % m ;
        a = (a + a) % m ;
        b >>= 1 ;
    }
    return ans ;
}
//快速幂
long long quick_pow(long long a , long long b , long long m)
{
    long long ans = 1 ;
    while (b)
    {
        if (b & 1)
            ans = quick_mul(ans , a , m);
        a = quick_mul(a , a , m) ;
        b >>= 1 ;
    }
    return ans ;
}


int a , b , c ;

LL res ;


int main ()
{
    scanf ("%lld%lld" , &n , &k) ;
    for (int i = 1 ; i <= n ; ++i)
    {
        num[i] = 1 ;
        fa[i] = i ;
    }
    for (int i = 1 ; i < n ; ++i)
    {
        scanf ("%d%d%d" , &a , &b , &c) ;
        if (c == 0)
        {
            int p = find_fa(a) ;
            int q = find_fa(b) ;
            if (p != q)
            {
                unit_fa(p , q) ;
            }
        }
    }
    res = quick_pow(n , k , MOD) ;
    for (int i = 1 ; i <= n ; ++i)
    {
        if (fa[i] == i)
        {
            res = (res - quick_pow(num[i] , k , MOD)) % MOD ;
        }
    }
    if (res < 0)
        printf ("%lld" , res + MOD) ;
    else
        printf ("%lld" , res) ;
}
