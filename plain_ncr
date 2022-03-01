ll ncr(ll n, ll r) {
    ll p = 1, k = 1;

    if (n - r < r) r = n - r;

    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;

            ll m = __gcd(p, k);

            p /= m;
            k /= m;

            n--;
            r--;
        }
    } else
        p = 1;

    return p;
}
