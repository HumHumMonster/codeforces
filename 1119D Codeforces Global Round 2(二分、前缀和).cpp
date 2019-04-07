/*
1119D Codeforces Global Round 2(二分、前缀和).cpp

一直优化一直优化。。。最后终于优化出来了
很有意思的一道题目。

需要用set去重
然后要离散化，存一下每个值的个数
再求前缀和
最后再用二分

*/

#include <stdio.h>
#include <iterator>
#include <set>
#include <vector>
#include <algorithm>
using namespace std ;

#define LL long long
vector <LL> V ;
vector <LL> res ;
vector <LL> num ;
vector <LL> go_sum ;
set <LL> S ;

LL now ;
vector <LL> num_sum ;
int n , m ;
LL l , r ;

inline LL _min(LL a , LL b){return a < b ? a : b ;}

int main ()
{
    scanf ("%d" , &n) ;
    while (n--)
    {
        scanf ("%lld" , &now) ;
        S.insert(now) ;
    }
    if (S.size() > 1)
    {
        set <LL> :: iterator it ;
        set <LL> :: iterator next = S.begin() ;
        ++next ;

        for (it = S.begin() ; next != S.end() ; ++next , ++it)
        {
            V.push_back(*next - *it) ;
        }
        sort(V.begin() , V.end()) ;
        LL now = 1 ;
        for (int i = 1 ; i < V.size() ; ++i)
        {
            //printf ("%d " , V[i]) ;
            if (V[i] == V[i - 1])
                ++now ;
            else
            {
                res.push_back(V[i - 1]) ;
                num.push_back(now) ;
                now = 1 ;
            }
        }
        res.push_back(V[V.size() - 1]) ;
        num.push_back(now) ;
        num_sum.push_back(num[0]) ;
        go_sum.push_back(num[0] * res[0]) ;
        for (int i = 1 ; i < num.size() ; ++i)
        {
            num_sum.push_back(num_sum[i - 1] + num[i]) ;
            go_sum.push_back(go_sum[i - 1] + num[i] * res[i]) ;
        }
    }
    scanf ("%d" , &m) ;
    if (S.size() == 1)
    {
        while (m--)
        {
            scanf ("%lld%lld" , &l , &r) ;
            printf ("%lld " , r - l + 1) ;
        }
        return 0 ;
    }
    while (m--)
    {
        scanf ("%lld%lld" , &l , &r) ;
        LL now = r - l + 1 ;
        LL sum = 0 ;
        int p = upper_bound(res.begin() , res.end() , now) - res.begin() - 1 ;
        //printf ("p = %d\n" , p) ;
        if (p != -1)
        {
            sum += go_sum[p] ;
            sum += (num_sum[num_sum.size() - 1] - num_sum[p]) * now ;
        }
        else
        {
            sum += num_sum[num_sum.size() - 1] * now ;
        }
        sum += now ;
        printf ("%lld " , sum) ;
    }

}
