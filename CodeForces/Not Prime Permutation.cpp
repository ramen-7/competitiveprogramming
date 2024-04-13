#include <bits/stdc++.h>
using namespace std;

/* clang-format off */

/* TYPES  */
#define ll long long


void solve()  {
	ll n;
	cin >> n;
	vector<ll> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (n <= 2) {
		cout << -1 << "\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] == 1) {
			cout << 3 << " ";
		} else if (arr[i] == 3) {
			cout << 1 << " ";
		} else {
			cout << arr[i] << " ";
		}
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
    	solve();
	}
}