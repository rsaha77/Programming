#ifdef DEBUG
#include "header.h"
#include "debug.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define sz(x) int((x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int(i)=0; (i)<(n);++(i))
#define ru(i,a,b) for(int(i)=a; (i)<(b);++(i))
#define FASTIO istream::sync_with_stdio(false); cin.tie(nullptr);

typedef long long int ll;
#define int ll

typedef pair <int,int> pii;
template <class T = int> inline T nxt () {T x; cin >> x; return x;}
template <class T> void chk_min (T& a, T b) {a = min (a, b);}
template <class T> void chk_max (T& a, T b) {a = max (a, b);}
template <class T> inline T gcd(T a,T b){return (!b? a : gcd(b,a%b));}
template <class T> inline T chk_max(T& a,T b,T c) {a = max(max(a,b),c);}
template <class T> inline T chk_min(T& a,T b,T c) {a = min(min(a,b),c);}
template <class T> bool ins(T a, T b, T c, T d) {return (0 <= a && a < c && 0 <= b && b < d);}
void inc_stk_lim () {rlimit R; getrlimit(RLIMIT_STACK, &R); R.rlim_cur = R.rlim_max; setrlimit(RLIMIT_STACK, &R);}

void solve () {
  
}

#undef int


void init () {
  #ifdef DEBUG
    freopen("in.txt", "r", stdin);
  #endif
  FASTIO
  inc_stk_lim();
}

int main() {
  init ();
  int T;
  cin >> T;
  rep(tc, T) {
    cout << "Case #" << tc + 1 << ": ";
    solve ();
  }
}
