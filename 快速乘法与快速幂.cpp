//快速乘法
long long quick_mul(long long a , long long b , long long m)
{
    long long ans = 0 ;
    while (b)
    {
        if (b & 1)
            ans = (ans + a) % m ;
        a = (a + a) % m ;
        b >>= 1 ;
    }
    return ans ;
}
//快速幂
long long quick_pow(long long a , long long b , long long m)
{
    long long ans = 1 ;
    while (b)
    {
        if (b & 1)
            ans = quick_mul(ans , a , m);
        a = quick_mul(a , a , m) ;
        b >>= 1 ;
    }
    return ans ;
}
