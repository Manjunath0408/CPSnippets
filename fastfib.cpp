void multiply(ll F[2][2], ll M[2][2])
{
    ll x = ((F[0][0] * M[0][0])%MOD + (F[0][1] * M[1][0])%MOD)%MOD;
    ll y = ((F[0][0] * M[0][1])%MOD + (F[0][1] * M[1][1]))%MOD;
    ll z = ((F[1][0] * M[0][0])%MOD + (F[1][1] * M[1][0])%MOD)%MOD;
    ll w = ((F[1][0] * M[0][1])%MOD + (F[1][1] * M[1][1])%MOD)%MOD;
     
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}
// Optimized version of power() in method 4
void power(ll F[2][2], ll n)
{
    if(n == 0 || n == 1)
       return;
    ll M[2][2] = {{1, 1}, {1, 0}};
     
    power(F, n / 2);
    multiply(F, F);
     
    if (n % 2 != 0)
        multiply(F, M);
}
// Function that returns nth Fibonacci number
ll fib(ll n)
{
    ll F[2][2] = {{1, 1}, {1, 0}};
    if (n == 0)
        return 0;
    power(F, n - 1);
 
    return F[0][0];
} 