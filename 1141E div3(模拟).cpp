/*
1141D div3(模拟).cpp

给出一个数组，长度为n
给出一个巨人血量h
每天巨人的血量加上a[i]
i超过n后继续从1开始
问巨人第几天死
如果不会死输出-1
*/

#include <stdio.h>
#define LL long long
LL h , n ;

const int maxn  = 2e5 + 10 ;
LL num[maxn] ;

LL cost ;
LL now ;
LL sum = 0 ;
LL res ;
LL p ;
int main ()
{
    scanf ("%lld%lld" , &h , &n) ;
    for (int i = 1 ; i <= n ; ++i)
    {
        scanf ("%lld" , &num[i]) ;
        num[i] = -num[i] ;
        sum += num[i] ;
        if (sum > cost)
            cost = sum ;
    }
    p = h ;
    for (int i = 1 ; i <= n ; ++i)
    {
        p -= num[i] ;
        if (p <= 0)
        {
            printf ("%d" , i) ;
            return 0 ;
        }
    }
    if (p >= h)
    {
        printf("-1") ;
        return 0 ;
    }

    p = h - cost ;
    now = p / sum ;
    res = now * n ;
    h -= sum * now ;
    for (int i = 1 ; i <= n ; ++i)
    {
        h -= num[i] ;
        if (h <= 0)
        {
            printf ("%lld" , i + res) ;
            return 0 ;
        }
    }
    for (int i = 1 ; i <= n ; ++i)
    {
        h -= num[i] ;
        if (h <= 0)
        {
            printf ("%lld" , i + res + n) ;
            return 0 ;
        }
    }

}
