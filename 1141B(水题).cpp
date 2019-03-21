/*
给出数组，问最多连续0的个数
可以首位相接
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
int num[maxn];
int main()
{
    int n ;
    scanf ("%d" , &n) ;
    for(int i = 0 ; i < n ; i++)
        scanf ("%d" , &num[i]) ;
    for(int i = 0 ; i < n ; i++)
        num[n+i] = num[i];
    int j = 0 ;
    int ans = 0 ;
    while(j<2*n)
    {
        int cnt = 0 ;
        while(num[j]==1)
        {
            j++;
            cnt++;
        }
        j++;
        ans=max(ans,cnt);
    }
    printf("%d" , ans) ;
}
