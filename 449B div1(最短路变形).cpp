/*

449B div1(最短路变形).cpp
假设你是某国（女儿国^_^）的主席，现在你为了省钱想去掉一些没用的铁路，给出城市数N，土路数量M和长度，铁路数量K和长度， 让你去掉那些不影响最小路径的铁路，问最多能去几条?
题目确定1号城市为首都，所有铁路都是从首都出发到其他城市的。



思路：
先记录下所有铁路的信息，再把铁路和土路全部记录到邻接表中然后Spfa求单源（点1）最短路径并记录最短路径数量，再与铁路比较。
如果到某点的最短距离小于铁路，那么这条铁路直接去掉，如果等于则判断最短路径数量是否为一，如果不唯一代表有其他路则这条铁路也去掉。
这题有一个点注意就是铁路要去重。
还有记录边的长度要用long long。
*/
#include <stdio.h>
#include <queue>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std ;

#define INF 0x3f3f3f3f
const int MAXN = 1e5 + 10 ;
int n , m ;

struct Edge
{
    int u , v , w ;
    Edge(int _u , int _v , int _w)
    {
        u = _u ;
        v = _v ;
        w = _w ;
    }
};

struct Node
{
    int d , u ;
    Node (int _d , int _u)
    {
        d = _d ;
        u = _u ;
    }
    friend bool operator < (Node a , Node b)
    {
        return a.d > b.d ;
    }
};

vector <Edge> edges;
vector <int> G[MAXN] ;
int dist[MAXN] ;
int vis[MAXN] ;
int p[MAXN] ;
int inq[MAXN] ;

void dijkstra(int s)
{
    priority_queue<Node> Q ;
    for (int i = 0 ; i <= n ; ++i)
        dist[i] = INF ;
    dist[s] = 0 ;
    memset (vis , 0 , sizeof (vis)) ;
    Q.push(Node(0 , s)) ;
    while (!Q.empty())
    {
        Node now = Q.top() ;
        Q.pop() ;
        int u = now.u ;
        if (vis[u])
            continue ;
        vis[u] = 1 ;
        for (int i = 0 ; i < G[u].size() ; ++i)
        {
            Edge e = edges[G[u][i]] ;
            if (dist[e.v] == dist[u] + e.w)         //有多条路可最近到达该点
                ++inq[e.v] ;
            if (dist[e.v] > dist[u] + e.w)
            {
                inq[e.v] = 1 ;
                dist[e.v] = dist[u] + e.w ;
                p[e.v] = G[u][i] ;
                Q.push(Node(dist[e.v] , e.v)) ;
            }
        }
    }
}

void addedge(int u , int v , int w)
{
    edges.push_back(Edge(u , v , w)) ;
    int sz = edges.size() ;
    G[u].push_back(sz - 1) ;
}

void init()
{
    for (int i = 0 ; i <= n ; ++i)
        G[i].clear() ;
    edges.clear() ;
}

int k ;
int res ;
int to[MAXN] , len[MAXN] ;
int main ()
{
    scanf ("%d%d%d" , &n , &m , &k) ;
    init() ;
    for (int i = 1 ; i <= m ; ++i)
    {
        int a , b , c ;
        scanf ("%d%d%d" , &a , &b , &c) ;
        addedge(a , b , c) ;
        addedge(b , a , c) ;
    }
    for (int i = 1 ; i <= k ; ++i)
    {
        scanf ("%d%d" , &to[i] , &len[i]) ;
        addedge(1 , to[i] , len[i]) ;
        addedge(to[i] , 1 , len[i]) ;
    }
    dijkstra(1) ;
    for (int i = 1 ; i <= k ; ++i)
    {
        if (dist[to[i]] == len[i])
        {
            if (inq[to[i]] > 1)
            {
                ++res ;
                --inq[to[i]] ;
            }
        }
        else if (dist[to[i]] < len[i])
            ++res ;
    }
    printf ("%d" , res) ;
    return 0 ;
}
