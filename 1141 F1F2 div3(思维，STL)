/*
1141 F1F2 div3(思维，STL)

给出数组，长度为n
求子串和重复最多的数的次数，并输出区间
数不能重复使用
*/


#include <stdio.h>
#include <map>
#include <vector>
#include <iterator>
#include <set>
using namespace std ;
#define LL long long
const int maxn = 15e2 + 10 ;
LL num[maxn] ;
int n ;

set <int> S ;
map <LL , vector <pair <int , int > > > M ;


int check(LL x)
{
    int l = -1 ;
    int r = -1 ;
    int res = 0 ;
    for (int i = 0 ; i < M[x].size() ; ++i)
    {
        if (r < M[x][i].first)
        {
            ++res ;
            r = M[x][i].second ;
        }
    }
    return res ;
}



int main ()
{
    scanf ("%d" , &n) ;
    for (int i = 1 ; i <= n ; ++i)
        scanf ("%lld" , &num[i]) ;
    for (int i = 1 ; i <= n ; ++i)
    {
        LL now = 0 ;
        for (int j = i ; j >= 0 ; --j)
        {
            now += num[j] ;
            S.insert(now) ;
            M[now].push_back(make_pair(j , i)) ;
        }
    }
    int res = 0 ;
    int id ;
    for (set <int> :: iterator it = S.begin() ; it != S.end() ; ++it)
    {
        int now = check(*it) ;
        if (now > res)
        {
            res = now ;
            id = *it ;
        }
    }
    printf ("%d\n" , res) ;
    int r = -1 ;
    for (int i = 0 ; i < M[id].size() ; ++i)
    {
        if (r < M[id][i].first)
        {
            printf ("%d %d\n" , M[id][i].first , M[id][i].second) ;
            r = M[id][i].second ;
        }
    }
}
