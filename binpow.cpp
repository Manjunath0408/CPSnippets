ll binpow(ll b,ll n){
  ll res = 1;
  while(n){
    if(n&1)res *=b;
    n/=2;
    b*=b;
  }
  return res;
}