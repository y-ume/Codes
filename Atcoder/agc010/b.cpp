// #include {{{
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <bitset>
#include <vector>
#include <complex>
#include <algorithm>
using namespace std;
// }}}
// #define {{{
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
// }}}

const int N = 1e5 + 10;
int n , a[N];

int main(){
  ll sum = 0;
  cin >> n;
  rep(i,0,n) cin >> a[i] , sum += a[i];
  ll one = ll(n) * (n + 1) / 2;
  if(sum % one != 0) {
    cout << "NO" << endl;
    return 0;
  }
  ll times = sum / one;
  rep(i,0,n) {
    ll dif = (a[i] - a[(i-1+n)%n]);
    // (times - t) - t * (n - 1) = dif
    // t * n = times - dif
    if((times - dif) % n != 0 || times - dif < 0){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
