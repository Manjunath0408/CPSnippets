long long int mod_pow(long long int a, long long int b, long long int mod) {
    long long int result = 1;
 
    while (b > 0) {
        if (b & 1)
            result = long long int(uint64_t(result) * a % mod);
 
        a = long long int(uint64_t(a) * a % mod);
        b >>= 1;
    }
 
    return result;
}
 
bool miller_rabin(long long int n) {
    if (n < 2)
        return false;
 
    for (long long int p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29})
        if (n % p == 0)
            return n == p;
 
    int r = __builtin_ctz(n - 1);
    long long int d = (n - 1) >> r;
 
    for (long long int a : {2, 7, 61}) {
        long long int x = mod_pow(a % n, d, n);
 
        if (x <= 1 || x == n - 1)
            continue;
 
        for (int i = 0; i < r - 1 && x != n - 1; i++)
            x = long long int(uint64_t(x) * x % n);
 
        if (x != n - 1)
            return false;
    }
 
    return true;
}
