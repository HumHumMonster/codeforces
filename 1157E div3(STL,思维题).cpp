/*
1157E div3(STL,思维题).cpp

给出一个a数组，一个b数组
要求得到c数组。c[i] = (a[i] + b[i]) % n
现在你可以改变b数组的位置
输出你能得到的最小字典序的c数组


思路简单。就是对每一个a[i]，lower_bound(n - a[i])
如果找不到，就拿最小的凑
于是就悲剧了。。。
过去一直对vector比较熟练，这次一看到就决定用vector来模拟
殊不知vector的erase()的复杂度是线性的。。。
所以就妥妥的超时了

用multiset不会超时，因为它是用红黑树为原理的
删除某个值的复杂度是O(1),删除某个迭代器位置是一个常数
删除一个区间是O(n)的。不会超时

真是一个残忍的消息。。。。
*/

#include <bits/stdc++.h>
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

int n ;
const int MAXN = 2e5 + 10 ;

int num[MAXN] ;
multiset <int> V ;
multiset <int> :: iterator it ;
int res[MAXN] ;
int now ;
int now1 , now2 ;
int main ()
{
    scanf ("%d" , &n) ;
    for (int i = 1 ; i <= n ; ++i)
        scanf ("%d" , &num[i]) ;
    for (int i = 1 ; i <= n ; ++i)
    {
        scanf ("%d" , &now) ;
        V.insert(now) ;
    }

    for (int i = 1 ; i <= n ; ++i)
    {
        now = (n - num[i]) % n ;
        it = V.lower_bound(now) ;
        if (it == V.end())
            it = V.begin() ;
        res[i] = (*it + num[i]) % n ;
        printf ("%d " , res[i]) ;
        V.erase(it) ;
    }
}
