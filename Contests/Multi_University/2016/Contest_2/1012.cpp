#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <bitset>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
const int N = 101010;
int T , n , m;
char s[N] , t[N];
char ok[N];
bitset<5001> B[3] , P[26] , Q[26][26];
int c[3];

int main(){
    scanf("%d",&T);
    rep(i,0,T){
        scanf("%d%d",&n,&m);
        scanf("%s%s",s, t + 1);
        rep(i,0,26) P[i].reset();
        rep(i,0,26) rep(j,0,26) Q[i][j].reset();
        rep(i,1,m+1) P[t[i] - 'a'][i] = 1;
        rep(i,2,m+1){
            int p = t[i-1] - 'a' , q = t[i] - 'a';
            if(p > q) swap(p , q);
            Q[p][q][i] = 1;
        }
        rep(i,0,3) B[i].reset();
        rep(i,0,3) c[i] = i;
        B[c[0]][0] = 1;
        fill(ok , ok + n , '0');ok[n] = 0;
        rep(i,0,n){
            swap(c[0] , c[1]);swap(c[1] , c[2]);
            B[c[0]].reset();B[c[0]][0] = 1;
            B[c[0]] |= B[c[2]]<<1&P[s[i] - 'a'];
            int p = s[i-1] - 'a' , q = s[i] - 'a';
            if(p > q) swap(p , q);
            if(i) B[c[0]] |= B[c[1]]<<2&Q[p][q];
            if(B[c[0]][m] == 1) ok[i-m+1] = '1';
        }
        puts(ok);
    }
    return 0;
}
