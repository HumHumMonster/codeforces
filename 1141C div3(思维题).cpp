/*
1141C div3(思维题)

要求一个数组a，长度为n
给出一个数组b，长度为n-1
b[i] = a[i + 1] - a[i] ;
并且a的数必须在1到n之间，而且不能重复。
输出数组，没有答案输出-1

in：
3
-2 1

out：
3 1 2 


in：
5
1 1 1 1

out：
1 2 3 4 5 

in：
4
-1 2 2

out：
-1

*/

#include<bits/stdc++.h>
using namespace std;
queue <int> Q ;
#define LL long long
set <LL> S ;
const int maxn = 1e7+10;
int num[maxn];
int res[maxn] ;
int vis[maxn] ;
int maxq = 1 , minq = 1 ;
int main()
{
    int n ;
    scanf ("%d" , &n) ;
    for (int i = 1 ; i < n ; ++i)
    {
        scanf ("%d" , &num[i]) ;
    }
    res[1] = 1 ;
    S.insert(1) ;
    for (int i = 2 ; i <= n ; ++i)
    {
        res[i] = res[i - 1] + num[i - 1] ;
        if (S.find(res[i]) != S.end())
        {
            printf("-1") ;
            return 0 ;
        }
        S.insert (res[i]) ;
        if (res[i] > maxq)
            maxq = res[i] ;
        if (res[i] < minq)
            minq = res[i] ;
        if (maxq - minq >= n)
        {
            printf("-1") ;
            return 0 ;
        }
    }
    for (int i = 1 ; i <= n ; ++i)
    {
        if (res[i] + 1 - minq > n)
        {
            printf ("-1") ;
            return 0 ;
        }
        Q.push(res[i] + 1 - minq) ;
    }
    while (!Q.empty())
    {
        printf("%d " , Q.front() ) ;
        Q.pop() ;
    }
}
