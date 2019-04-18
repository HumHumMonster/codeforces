/*
1153C div2(贪心).cpp

给出一个 n ，给出一个长度 为 n 的字符串


         
你可以把？改成你需要的左括号或者右括号
问能不能得到一个字符串，他的前缀都不是标准的括号表达式，而它自己是
有的话输出字符串，没有的话输出:(

输入
6
(?????
输出
(()())
 
输入
10
(???(???(?
输出
:(


思路：
因为之前上数据结构课老师讲了一个用递归或者栈来给点着色的问题
这道题一看到就很自然的想到了用递归
结果稳稳的超时呀。。。Time limit exceeded on test 37

比赛后看题解才知道原来是贪心
先得到原字符串中左括号，右括号和问号的个数
然后可以得到问号有几个要变成左括号，几个变成右括号

然后把靠前的问好都变成左括号，靠后的都变成右括号，再看得到的式子符不符合要求就好了
这么简单都想不到。。。还需努力
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

int n ;
string str ;
string res ;
int main ()
{
    scanf ("%d" , &n) ;
    cin >> str ;
    if (n % 2)
    {
        printf (":(") ;
        return 0 ;
    }
    int wenhao = 0 ;
    int left = 0 ;
    int right = 0 ;
    for (int i = 0 ; i < str.size() ; ++i)
    {
        if (str[i] == '?')
            ++wenhao ;
        else if (str[i] == '(')
            ++left ;
        else
            ++right ;
    }
    int toleft = 0 ;
    int toright = 0 ;
    if (left < right)
    {
        toleft += right - left ;
        wenhao -= right - left ;
    }
    else
    {
        toright += left - right ;
        wenhao -= left - right ;
    }
    if (wenhao < 0)
    {
        printf (":(") ;
        return 0 ;
    }
    toright += wenhao / 2 ;
    toleft += wenhao / 2 ;
    for (int i = 0 ; i < str.size() ; ++i)
    {
        if (str[i] == '?')
        {
            if (toleft)
            {
                --toleft ;
                res += '(' ;
            }
            else
                res += ')' ;
        }
        else
            res += str[i] ;
    }
    left = 0 ;
    right = 0 ;
    for (int i = 0 ; i < res.size() ; ++i)
    {
        if (res[i] == '(')
            ++left ;
        else
            ++right ;
        //printf ("l = %d   r = %d\n" , left , right ) ;
        if (left <= right)
        {
            if (i == res.size() - 1 && left == right)
                continue ;
            printf (":(") ;
            return 0 ;
        }
    }
    cout << res ;
}

