#include <bits/stdc++.h>
using namespace std;

/* clang-format off */

/* TYPES  */
#define ll long long
# define pair<ll, ll> pll;
//bool vis[1000+1][1000+1];
ll MOD = 998244353;

void solve() {
	ll x, y;
	cin >> x >> y;
	ll ans = 0;
	ll a, b;
	if (x % 2 == 0 && y % 2 == 1) {
		a = x;
		b = y;
	} else if (x % 2 == 1 && y % 2 == 1) {
		a = y;
		b = x;
	} else {
		a = x;
		b = y;
	}
	
	x = a;
	y = b;
	
	ll xHalf = ceil(x/2.0);
	ll yHalf = ceil(y/2.0);

	if (x % 2 == 0 && y % 2 == 1) {
		//entire row of (x, y) & (x+1, y) is taken
		if (xHalf >= (y-1)) {
			for (ll i = xHalf; i <= xHalf+1; i++) {
				for (ll j = 1; j <= y; j++) {
					ans = (ans + (i*yHalf)%MOD)%MOD;	
				}
			}
		} else if (yHalf >= (x-1)) {
			// entire row of x is taken
			for (ll i = 1; i <= y; i++) {
				ans = (ans + (i*xHalf)%MOD)%MOD;	
			}
		}else {
			for (ll i = xHalf; i <= xHalf+1; i++) {
				ans = (ans + (i*yHalf)%MOD)%MOD;
			}	
		} 
	} else if (x% 2 == 0 && y % 2 == 0) {
		if (xHalf >= (y-1)) {
			for (ll i = xHalf; i <= xHalf+1; i++) {
				for (ll j = 1; j <= y; j++) {
					ans = (ans + (i*j)%MOD)%MOD;	
				}
			}
		} else if (yHalf >= (x-1)) {
			// entire col of y is taken
			for (ll i = yHalf; i <= yHalf+1; i++) {
				for (ll j = 1; j <= x; j++) {
					ans = (ans + (i*j)%MOD)%MOD;	
				}
			}
		}else {
			for (ll i = xHalf; i <= xHalf+1; i++) {
				for (ll j = yHalf; j <= yHalf + 1; j++) {
					ans = (ans + (i*j)%MOD)%MOD;	
				}
			}	
		} 
	} else if (x%2==1 && y%2 == 1) {
//		cout << xHalf << ", " <<yHalf <<endl;
		if (xHalf >= (y)) {
				for (ll j = 1; j <= y; j++) {
					ans = (ans + (xHalf*j)%MOD)%MOD;	
				}
		} else if (yHalf >= (x)) {
			// entire col of y is taken
				for (ll j = 1; j <= x; j++) {
					ans = (ans + (yHalf*j)%MOD)%MOD;	
				}
		}else {
			ans = (ans+(xHalf*yHalf)%MOD)%MOD;	
		} 
	} else {
		cout << "eroooooooooooooooooooooooooooor" << endl;
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
//    memset(vis, false, sizeof(vis));
    while (t--) {
    	solve();	
	}
}