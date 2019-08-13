/*
280C div1(期望线性性).cpp


题目大意 
给出一棵含n个白点的有根树,每次随机选择一个还没有被染黑的节点,将这个节点和这个节点子树中的所有点染黑. 
问期望操作多少次后所有点都被染黑. 
N<=100000

整棵树的期望操作次数太大，难以找到方法。这时我们需要突破口。 
该如何将大问题转化为小问题呢？我们发现，一棵树是可以分成好几颗子树的，而子树分解的最终状态就是所有的点。那么，我们是不是可以计算出 每个点被染黑的期望操作次数，然后相加就是整棵树的了？答案是当然可以。 
这里需要注意的是，对于每个点的操作次数是指的在这个点上的操作。对于每一个点，如果其祖先被染黑了，它自己也会被顺带染黑，而这个对于该点来说是没有进行操作的。所以得出对于点x：E(x)=1/dep[x] 
dfs就可以了
*/

#include <stdio.h>
#include <vector>
using namespace std ;
const int MAXN = 1e5 + 10 ;
int n ;
int a , b ;
double res = 0 ;
vector <int> V[MAXN] ;
void DFS(int h , int pre , int dep)
{
    res += (double)1 / (double)dep ;
    for (int i = 0 ; i < V[h].size() ; ++i)
    {
        if (V[h][i] == pre)
            continue ;
        DFS(V[h][i] , h , dep + 1) ;
    }
}

int main ()
{
    scanf ("%d" , &n) ;
    for (int i = 1 ; i < n ; ++i)
    {
        scanf ("%d%d" , &a , &b) ;
        V[a].push_back(b) ;
        V[b].push_back(a) ;
    }
    DFS(1 , 0 , 1) ;
    printf ("%f" , res) ;
}
