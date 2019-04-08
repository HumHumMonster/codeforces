/*
1119A Codeforces Global Round 2(贪心).cpp

给出n种木棍，长度分别是
2^0  2^1  2^2 ....2^(n - 1)
告诉每种木棍的根数
问最多可以组成多少三角形


用pre表示之前剩下的
当前的先尽可能和之前的配对
再看看能不能自己三个配对
把剩下的加入pre中

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

const int maxn = 3e5 + 10 ;

LL num[maxn] ;
LL res ;
LL pre ;
int n ;


int main ()
{
    scanf ("%d" , &n) ;
    for (int i = 1 ; i <= n ; ++i)
        scanf ("%lld" , &num[i]) ;
    for (int i = 1 ; i <= n ; ++i)
    {
        LL now = _min(pre , num[i] / 2) ;
        res += now ;
        num[i] -= now * 2 ;
        pre -= now ;
        if (num[i])
        {
            now = num[i] / 3 ;
            res += now ;
            num[i] -= now * 3 ;
        }
        pre += num[i] ;
    }
    printf ("%lld" , res) ;
}
