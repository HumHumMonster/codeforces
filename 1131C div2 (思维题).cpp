/*
1131C div2 (思维题)

题意：
给出一个数组
你可以对数组中的数的位置进行随意调整
使得最后数组相邻两个数之差的最大值最小
数组首位相连

思路：
把数组排序后
先输出奇数位置
再将偶数位置倒序输出
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


const int maxn = 1e2 + 10 ;
int n ;
int num[maxn] ;
stack <int> Q ;

int main ()
{
    scanf ("%d" , &n) ;
    for (int i = 1 ; i <= n ; ++i)
    {
        scanf ("%d" , &num[i]) ;
    }
    sort (num + 1 ,  num + 1 + n) ;
    for (int i = 1 ; i <= n ; i += 2)
    {
        printf ("%d " , num[i]) ;
    }
    for (int i = 2 ; i <= n ; i += 2)
    {
        Q.push(num[i]) ;
    }
    while (!Q.empty())
    {
        printf ("%d " , Q.top()) ;
        Q.pop() ;
    }
}
