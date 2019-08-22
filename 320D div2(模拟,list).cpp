/*
320D div2(模拟,list).cpp

题意
给一个n，代表有n个人
每个人有一个值，所有人的值都是1~n之间，且不重复
每回合，每个人可以杀自己右边的人，可以同时杀别人又被别人杀

问过几回合每个人都不能再杀人了


用list模拟过程

*/


#include <cstdio>
#include <cstring>
#include <algorithm>
#include <list>
using namespace std ;

const int MAXN = 100010 ;

list <int> killing ;
list <int> :: iterator it1 , it2 ;

int num[MAXN] , nex[MAXN] ;

int n ;

int main ()
{
    scanf ("%d" , &n) ;
    for (int i = 1 ; i <= n ; ++i)
    {
        scanf ("%d" , &num[i]) ;
        if (num[i] < num[i - 1])
            killing.push_back(i - 1) ;
        nex[i] = i + 1 ;
    }
    num[n + 1] = n + 1 ;
    int step = 0 ;
    while (!killing.empty())
    {
        ++step ;
        it2 = killing.end() ;
        --it2 ;
        bool flag = true ;
        do
        {
            it1 = it2 -- ;
            int now1 = *it1 , now2 = *it2 ;
            nex[now1] = nex[nex[now1]] ;
            if (it1 == killing.begin())
                flag = false ;
            if (it1 == killing.begin())
                flag = false ;
            if (num[now1] < num[nex[now1]])
                killing.erase(it1) ;
            else if (it1 != killing.begin())
                if (nex[now2] == now1)
                    killing.erase(it1) ;
        }while (flag) ;
    }
    printf ("%d" , step) ;
}
