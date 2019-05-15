/*
C2.cpp
给出n个点的xy坐标，所有点两两连成一条直线
问最后有几个交点
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

const int MAXN = 1005 ;
int x[MAXN] , y[MAXN] ;

map <pair <int , int> , set <LL> > slope_map ;

int gcd (int a , int b)
{
    if (a == 0)
        return b ;
    return gcd(b % a , a) ;
}

int n ;

int main ()
{
    scanf ("%d" , &n) ;
    for (int i = 1 ; i <= n ; ++i)
        scanf ("%d%d" , &x[i] , &y[i]) ;

    LL total = 0 , res = 0 ;
    for (int i = 1 ; i <= n - 1 ; ++i)
    {
        for (int j = i + 1 ; j <= n ; ++j)
        {
            int x1 = x[i] , y1 = y[i] ;
            int x2 = x[j] , y2 = y[j] ;
            int a = y1 - y2 , b = x1 - x2 ;
            int d = gcd(a , b) ;
            a /= d ;
            b /= d ;
            if (a < 0 || (a == 0 && b < 0))
            {
                a = -a ;
                b = -b ;
            }

            pair <int , int> slope(a , b) ;
            LL c = 1LL * a * x1 - 1LL * b * y1 ;
            if (!slope_map[slope].count(c))
            {
                ++total ;
                slope_map[slope].insert(c) ;
                res += total - slope_map[slope].size() ;
            }
        }
    }
    printf ("%lld" , res) ;
}
