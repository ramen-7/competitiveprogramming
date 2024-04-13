#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//define pll pair<long, long>;
const char enl = '\n';

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


bool slope(ll a1, ll b1, ll a2, ll b2, ll a3, ll b3) {
	ll x1 = (a1 - a2);
	ll y1 = (b1 - b2);
	ll x2 = (a3 - a2);
	ll y2 = (b3 - b2);
	
	return (x1*y2 - x2*y1 != 0);	
}            

bool compare(const array<ll, 4>& a, const array<ll, 4>& b) {
	return a[2] < b[2];
}

void solve() {
	ll n;
	cin >> n;
	vector<array<ll, 4>> arr(n);
	for (ll i = 0; i < n; i++) {
		ll x, y, v;
		cin >> x >> y >> v;
		arr[i] = {x, y, v, i};
	}	
	
	sort(arr.begin(), arr.end(), compare);
	
	for (int i = 0; i < n-1; i++) {
		if (arr[i][2] == arr[i+1][2]) {
			for (int j = n-1; j >= 0; j--) {
				if (slope(arr[i][0], arr[i][1], arr[i+1][0], arr[i+1][1], arr[j][0], arr[j][1])) {
					cout << 3 << enl;
					cout << (i+1) << " " << (j+1) << " " << (i+2) << enl;
					return;
				}
			}
		}
	}
	
	cout << -1 << enl;
}

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
//    cout << "t = " << t << endl;
    while (t --> 0) {
    	solve();
	}
}