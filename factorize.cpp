ll prime[MAX_N + 5];
bool isPrime[MAX_N + 5];

void seive(ll n) {
    memset(prime, 0, sizeof(prime));
    memset(isPrime, 1, sizeof(isPrime));

    for (ll p = 2; p <= n; p++) {
        if (isPrime[p] == 1) {
            prime[p] = p;
            for (ll i = p * p; i <= n; i += p) {
                isPrime[i] = 0;
                if (prime[i] == 0) prime[i] = p;
            }
        }
    }
}
