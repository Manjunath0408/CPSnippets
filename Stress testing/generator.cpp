#include <bits/stdc++.h>
using namespace std;
int main(){
  cout << 1 << endl;
  mt19937 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());
  int n = rng()%(20) + 1;
  int m = rng()%(20) + 1;
  cout << n << " " << m << endl;
  cout<<endl;
}
