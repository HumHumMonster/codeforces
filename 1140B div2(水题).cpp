/*
1140B div2(水题)

给出长度为n的字符串
字符串只有'>'或'<'
<可以把它左边的东西删掉
>可以把它右边的东西删掉

你可以删除任意位置的字符
使得操作后，可以只用>或者<让字符串中只有一种字符

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

const int maxn = 1e4 + 10 ;
int n ;
int num[maxn] ;
int res[maxn] ;

string str ;

int main ()
{
    int T ;
    scanf ("%d" , &T ) ;
    while (T--)
    {
        scanf ("%d" , &n) ;
        cin >> str ;
        int l = 200 , r = -200 ;
        for (int i = 0 ; str[i] != '\0' ; ++i)
        {
            if (str[i] == '>')
            {
                l = i + 1 ;
                break ;
            }
        }
        for (int i = str.size() - 1 ; i >= 0 ; --i)
        {
            if (str[i] == '<')
            {
                r = i + 1 ;
                break ;
            }
        }
        printf ("%d\n" , _min(l - 1 , n - r)) ;
    }
}
