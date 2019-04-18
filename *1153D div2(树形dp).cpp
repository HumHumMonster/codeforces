/*
1153D div2(树形dp).cpp

还能说啥呢。。。第一次做到树形dp的题目，但是理解以后其实也不难

给出一个树。节点标记 1 或者 0
标记 1 的节点的值等于它子节点中的最大值
标记 0 的节点的值等于它子节点中的最小值
叶子节点可以自己定义值，值的范围是 1 到 叶子节点的个数，每个值只能用一次

首先建树，代码中的leave[i]代表以i节点为根的子树的叶子节点的个数
val[i]代表以i节点为根的子树得到的最大值可以在leave[i]排多大

如果遇到max节点
val[h] = max ( leave[h] - leave[V[h][i]] + val[V[h][i]] )
如果遇到min节点
val[h] += val[V[h][i]] - 1 (0 <= i <= V[h].size())
结果输出val[1]就好啦
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

int val[maxn] ;
int fa[maxn] ;

int leave[maxn] ;

int n ;
vector <int> V[maxn] ;

int op[maxn] ;

void DFS(int h)
{
    if (V[h].size() == 0)
    {
        leave[h] = 1 ;
        val[h] = 1 ;
        //printf ("h = %d   val = %d   leave = %d\n" , h , val[h] , leave[h]) ;
        return ;
    }
    for (int i = 0 ; i < V[h].size() ; ++i)
    {
        DFS(V[h][i]) ;
        leave[h] += leave[V[h][i]] ;
    }
    if (op[h] == 1)
    {
        val[h] = 0 ;
        for (int i = 0 ; i < V[h].size() ; ++i)
        {
            if (leave[h] - leave[V[h][i]] + val[V[h][i]] > val[h])
                val[h] = leave[h] - leave[V[h][i]] + val[V[h][i]] ;
        }
    }
    else
    {
        val[h] = 1 ;
        for (int i = 0 ; i < V[h].size() ; ++i)
        {
            val[h] += val[V[h][i]] - 1 ;
        }
    }
    //printf ("h = %d   val = %d   leave = %d\n" , h , val[h] , leave[h]) ;
}

int main ()
{
    scanf ("%d" , &n) ;
    for (int i = 1 ; i <= n ; ++i)
        scanf ("%d" , &op[i]) ;
    for (int i = 2 ; i <= n ; ++i)
    {
        scanf ("%d" , &fa[i]) ;
        V[fa[i]].push_back(i) ;
    }
    DFS(1) ;
    printf ("%d" , val[1]) ;
}
