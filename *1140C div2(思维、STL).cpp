/*
1140C div2(思维、STL)

题意：
有一张专辑，里面有n首歌
你可以从n首歌中选出不大于k首歌

每一首歌都有自己的长度t[i]与美妙度b[i]
你可以获得的幸福感
等于你选择的所有歌曲的长度之和乘以你选择的所有歌曲的最小美妙度
求最大幸福感

思路：
按照美妙度排序，使得遍历到i时，美妙度最小的就是b[i]
用一个优先队列来存储最长的长度
复杂度O(n)
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


int n , k ;


const int maxn = 3e5 + 10 ;



pair <LL , LL> song[maxn] ;

priority_queue<LL , vector<LL >,greater<LL > > que ;//从小到大排列。

LL sum = 0 ;
LL res = 0 ;
LL now ;
int main ()
{
    scanf ("%d%d" , &n , &k) ;
    for (int i = 1 ; i <= n ; ++i)
    {
        scanf ("%lld%lld" , &song[i].second , &song[i].first) ;
    }
    sort (song + 1 , song + 1 + n) ;
    for (int i = n ; i >= 1 ; --i)
    {
        sum += song[i].second ;
        que.push(song[i].second) ;
        if (que.size() > k)
        {
            LL go = que.top() ;
            sum -= go ;
            que.pop() ;
            if (go == song[i].second)
                continue ;
        }
        now = sum * song[i].first ;
        if (now > res)
            res = now ;
    }
    printf ("%lld" , res) ;
}
