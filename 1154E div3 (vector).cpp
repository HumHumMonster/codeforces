/*
1154E div3 (vector).cpp

给出一个 n , 一个 k 
然后给 n 个人赋值,每个人的值都不同

1 <= a[i],n <= 2e5

要求每一轮在在当前的人中找到值最大的人
然后把这个人和他左边 k 个右边 k 个加到队伍中去
每次\加入一队或者二队,交替的

最后输出1到n每个人的去向

一开始还用二分...2000ms都超时了一次
后来用vector的删除操作468 ms过
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

const int maxn = 2e5 + 10 ;

int vis[maxn] ;

struct Node
{
    int id ;
    int val ;
}node[maxn];

int id[maxn] ;
int num[maxn] ;
int gone[maxn] ;
vector <int> val ;
vector <int> vid ;
int n ;
int k ;

int now ;

vector <int> :: iterator it , pp ;

int nowid ;

int main ()
{
    scanf ("%d%d" , &n , &k) ;
    for (int i = 1 ; i <= n ; ++i)
    {
        scanf ("%d" , &now) ;
        id[now] = i ;
        num[i] = now ;
        //val.push_back(now) ;
        vid.push_back(i) ;
    }
    int nowval = n ;
    int uu = 1 ;
    while (vid.size() != 0)
    {
        //printf ("%d\n" , vid.size()) ;
        now = nowval ;
        if (now == 0)
            break ;
        //printf ("now = %d\n" , now) ;
        int p = id[now] ;
        int q = lower_bound(vid.begin() , vid.end() , p) - vid.begin();
        int l = q - k ;
        int r = q + k ;
        if (l < 0)
            l = 0 ;
        if (r >= vid.size())
            r = vid.size() - 1 ;
        //printf ("l = %d  r = %d\n" , l , r) ;
        for (int i = l ; i <= r ; ++i)
        {
            vis[vid[i]] = uu ;
            gone[num[vid[i]]] = 1 ;
        }
        vid.erase(vid.begin() + l , vid.begin() + r + 1) ;
        if (uu == 2)
            uu = 1 ;
        else
            uu = 2 ;
        while (gone[nowval])
        {
            --nowval ;
        }
    }
    for (int i = 1 ; i <= n ; ++i)
    {
        printf ("%d" , vis[i]) ;
    }
}
