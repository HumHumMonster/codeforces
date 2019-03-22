/*
1139B div2 (思维题)

题意：
给出一个数组长度为n
要求用掉所有的数求一个和
在每一个位置加的值要小于等于这个位置的值
在每一个位置加的值要小于这个位置后一个加的值
大于前一个位置的值。

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


string str ;
int n ;
const int maxn = 2e5 + 10 ;
LL num[maxn] ;
LL res = 0 ;

LL last = INF ;

int main ()
{
    scanf ("%d" , &n) ;
    for (int i = 1 ; i <= n ; ++i)
        scanf ("%lld" , &num[i]) ;
    for (int i = n ; i >= 1 ; --i)
    {
        if (num[i] < last)
        {
            last = num[i] ;
            res += num[i] ;
        }
        else
        {
            last = last - 1 ;
            res += last ;
        }
        if (last == 1)
            break ;
    }
    printf ("%lld" , res) ;
}
