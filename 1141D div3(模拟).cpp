/*
1141D div3(模拟)

有左右两种鞋子
给出两个字符串，分别代表两种鞋子的种类
种类相同可以配一对，一只鞋子不能重复使用
其中‘？’可以和任意类型配对
问最多可以配对多少对
并输出配对的鞋子的左右脚在数组中的序号
*/

#include<bits/stdc++.h>
using namespace std;
queue <int> Q ;
#define LL long long
const int maxn = 15e4 + 10 ;
string str1 , str2 ;

int num1[30] , num2[30];

vector <int> v1[30] , v2[30] ;
vector <int> enen1 , enen2 ;
int en1 , en2 ;

int vis1[maxn] , vis2[maxn] ;

inline int _min(int a , int b){return a < b ? a : b ;}

int main()
{
    int n ;
    scanf ("%d" , &n) ;
    cin >> str1 >> str2 ;
    for (int i = 0 ; str1[i] != '\0' ; ++i)
    {
        if (str1[i] == '?')
        {
            ++en1 ;
            enen1.push_back(i) ;
        }
        else
        {
            v1[str1[i] - 'a' + 1].push_back(i) ;
        }

        if (str2[i] == '?')
        {
            ++en2 ;
            enen2.push_back(i) ;
        }
        else
        {
            v2[str2[i] - 'a' + 1].push_back(i) ;
        }
    }
    int res = 0 ;
    for (int i = 1 ; i <= 26 ; ++i)
    {
        res += _min(v1[i].size() , v2[i].size()) ;
    }
    int p1 = en1 , p2 = en2 ;
    p1 = _min(p1 , n - res - en2) ;
    p2 = _min(p2 , n - res - en1) ;
    res += p1 ;
    res += p2 ;
    int q = _min(en1 - p1 , en2 - p2) ;
    res += q ;
    printf ("%d\n" , res) ;
    for (int i = 1 ; i <= 26 ; ++i)
    {
        int now = _min(v1[i].size() , v2[i].size()) ;
        for (int j = 0 ; j < now ; ++j)
        {
            printf ("%d %d\n" , v1[i][j] + 1 , v2[i][j] + 1) ;
            vis1[v1[i][j]] = 1 ;
            vis2[v2[i][j]] = 1 ;
        }
    }

    //printf ("p1 = %d   p2 = %d  q = %d\n" , p1 , p2 , q) ;


    int id1 = 0 ;
    for (int i = 0 ; str1[i] != '\0' ; ++i)
    {
        if (p1 == 0)
            break ;
        if (vis2[i] == 0 && str2[i] != '?')
        {
            printf ("%d %d\n" , enen1[id1] + 1 , i + 1) ;
            ++id1 ;
            --p1 ;
        }
    }

    int id2 = 0 ;
    for (int i = 0 ; str1[i] != '\0' ; ++i)
    {
        if (p2 == 0)
            break ;
        if (vis1[i] == 0 && str1[i] != '?')
        {
            printf ("%d %d\n" , i + 1 , enen2[id2] + 1) ;
            ++id2 ;
            --p2 ;
        }
    }

    while (q--)
    {
        printf ("%d %d\n" , enen1[id1] + 1  ,enen2[id2] + 1) ;
        ++id1 ;
        ++id2 ;
    }
}
