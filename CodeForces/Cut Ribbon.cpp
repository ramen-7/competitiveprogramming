#include <bits/stdc++.h>
using namespace std;

int solve(int s, int m, int l, int n) {
	int ss = n/s;
	int sl = n/l;
	int sm = n/m;
	int ans = INT_MIN;
	for (int i = 0; i <= sl; i++) {
		for (int j = 0; j <= sm; j++) {
			for (int k = 0; k <= ss; k++) {
				int sum = s*k + m*j + l*i;
				if (sum == n) {
					ans = max(ans, (i+j+k));
				}
			}
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
		int s, m, l;
		int a, b, c, n;
    	cin >> n >> a >> b >> c;
    	if ((a >= b) && (a >= c)) {
    		l = a;
    		if (b >= c) {
    			m = b;
    			s = c;
			} else {
				m = c;
    			s = b;
			}
		} else if ((b >= a) && (b >= c)) {
			l = b;
			if (a >= c) {
				m = a;
				s = c;
			} else {
				m = c;
				s = a;
			}
		} else if ((c >= a) && (c >= b)) {
			l = c;
			if (a >= b) {
				m = a;
				s = b;
			} else {
				m = b;
				s = a;
			}
		}
		unordered_map<int, int> hashmap;
		int ss = n/s;
		int sl = n/l;
		int sm = n/m;
		for (int i = 0; i <= sl; i++) {
			for (int j = 0; j <= sm; j++) { 
				int sum = i*l +j*m;
				if (hashmap.find(sum) != hashmap.end()) {
					hashmap[sum] = max(hashmap[sum], (i+j));
				} else {
					hashmap[sum] = i+j;
				}
			}
		}
		int ans = INT_MIN;
		for (int i = ss; i >= 0; i--) {
			int cur = i*s;
			int rem = n - cur;
			if (hashmap.find(rem) != hashmap.end()) {
				ans = max(hashmap[rem] + i, ans);
			}
		}
		cout << ans << endl;
}