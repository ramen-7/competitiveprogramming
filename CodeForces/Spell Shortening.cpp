#include <bits/stdc++.h>
using namespace std;

/* clang-format off */

/* TYPES  */
#define ll long long


void solve()  {
	ll n;
	cin >> n;
	string s;
	cin >> s;
	bool check = false;
	string ans = "";
	char cur = s[0];
	for (int i = 0; i < n-1; i++) {
		if (!check && s[i] <= s[i+1]) {
			ans += s[i];
		}else if (!check && s[i] > s[i+1]) {
			check = true;
		} else if (check) {
			ans += s[i];
		}
	}
	if (check) {
		ans += s.back();
	}
//	cout << ans.size() << ", " << ans << "\n";
	if (ans.size() == n) {
		ans.pop_back();
	}
	cout << ans << "\n";
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