vll Log(MAX_N);
ll n, dp[21][MAX_N];

void build() {
    Log[1] = 0;
    rep(i, 2, MAX_N) Log[i] = Log[i / 2] + 1;
    rep(i, 0, n) dp[0][i] = v[i];

    for (ll i = 1; i < 21; ++i)
        for (ll j = 0; j + (1 << (i - 1)) < n; ++j)
            dp[i][j] = f(dp[i - 1][j], dp[i - 1][j + (1 << (i - 1))]);
}

ll query(ll l, ll r) {
    if (l > r) return 0;
    ll p = Log[r - l + 1];
    return f(dp[p][l], dp[p][r - (1 << p) + 1]);
}

// Here r is inclusive
