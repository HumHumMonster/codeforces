/*
给出数n与m
可以对n乘以2或者乘以3使得n等于m
最少需要多少步操作
如果不可能输出-1
*/
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std ;

#define LL long long

LL a , b ;

int main ()
{
    scanf ("%lld%lld" , &a , &b) ;
    if (b % a != 0)
    {
        printf ("-1") ;
        return 0 ;
    }
    LL c = b / a ;

    int num2 = 0 ;
    while (c % 2 == 0)
    {
        c /= 2 ;
        num2 ++ ;
    }
    int num3 = 0 ;
    while (c % 3 == 0)
    {
        c /= 3 ;
        num3 ++ ;
    }
    if (c != 1)
    {
        printf ("-1") ;
    }
    else
        printf ("%d" , num3 + num2) ;
}
