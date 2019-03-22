/*
1139A div2 (签到)

题意：
给出一个string，由数字1~9构成
有很多子串，每个子串都是一个数
如123就是一百二十三
问由多少个值为偶数的子串
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

string str ;
int n ;

LL res = 0 ;

int main ()
{
    scanf ("%d" , &n) ;
    cin >> str ;
    for (int i = 0 ; str[i] != '\0' ; ++i)
    {
        if ((str[i] - '0') % 2 == 0)
            res += i + 1 ;
    }
    printf ("%lld" , res) ;
}
