/*
73A Codeforces Beta Round #66.cpp

给出一个立方体的三个棱长度，给你一个k，代表你可以切几刀
问最多切成几块

惊了！水题写了半天，
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


LL k , num[4] , res[4] ;

void Show()
{
    printf ("%lld\n" , res[1] * res[2] * res[3]) ;
}

int main ()
{
    for (int i = 1 ; i <= 3 ; ++i)
    {
        scanf ("%lld" , &num[i]) ;
        --num[i] ;
        res[i] = 1 ;
    }
    sort (num + 1 , num + 3 + 1) ;
    scanf ("%lld" , &k) ;
    int cut ;
    int elsecut ;
    if (k < num[1] * 3)
    {
        cut = k / 3 ;
        elsecut = k % 3 ;
        for (int i = 1 ; i <= 3 ; ++i)
        {
            res[i] += cut ;
        }
        if (elsecut)
        {
            ++res[2] ;
            --elsecut ;
        }
        if (elsecut)
        {
            ++res[3] ;
            --elsecut ;
        }
        Show() ;
        return 0 ;
    }
    else
    {
        k -= 3 * num[1] ;
        cut = num[1] ;
        for (int i = 1 ; i <= 3 ; ++i)
        {
            res[i] += cut ;
            num[i] -= cut ;
        }
    }


    if (k < num[2] * 2)
    {
        cut = k / 2 ;
        elsecut = k % 2 ;
        for (int i = 2 ; i <= 3 ; ++i)
        {
            res[i] += cut ;
        }
        if (elsecut)
        {
            ++res[3] ;
            --elsecut ;
        }
        Show() ;
        return 0 ;
    }
    else
    {
        k -= 2 * num[2] ;
        cut = num[2] ;
        for (int i = 2 ; i <= 3 ; ++i)
        {
            res[i] += cut ;
            num[i] -= cut ;
        }
    }
    if (k < num[3])
    {
        res[3] += k ;
    }
    else
    {
        res[3] += num[3] ;
    }
    Show() ;


}
