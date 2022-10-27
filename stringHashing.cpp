class stringHashing {
public:
  ll d, x, y;
  ll p = 31;
  ll m = 1e9 + 7;

  ll compute_hash(string &s) {
    ll hash_value = 0;
    ll p_pow = 1;
    for (char c : s) {
      hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
      p_pow = (p_pow * p) % m;
    }
    return hash_value;
  }

  void extendedEuclid(ll A, ll B) {
    if (B == 0) {
      d = A;
      x = 1;
      y = 0;
    } else {
      extendedEuclid(B, A % B);
      ll temp = x;
      x = y;
      y = temp - (A / B) * y;
    }
  }

  ll modInv(ll A, ll M) {
    extendedEuclid(A, M);
    return (x % M + M) % M;
  }

  vll rolling_hash(string &s, int k) {
    ll hash_value = 0;
    ll p_pow = 1;
    ll p_inv = modInv(p, m);
    vll hash;

    for (int i = 0; i < k; ++i) {
      hash_value = (hash_value + (s[i] - 'a' + 1) * p_pow) % m;
      if (i < k - 1) {
        p_pow = (p_pow * p) % m;
      }
    }
    hash.pb(hash_value);

    for (int i = k; i < s.size(); ++i) {
      ll val = (s[i - k] - 'a' + 1);
      hash_value = (hash_value - val + m) % m;
      hash_value = (hash_value * p_inv) % m;
      val = (s[i] - 'a' + 1);
      hash_value = (hash_value + (val * p_pow)) % m;
      hash.pb(hash_value);
    }

    return hash;
  }
};