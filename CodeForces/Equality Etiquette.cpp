#include <bits/stdc++.h>
using namespace std;

/* clang-format off */

/* TYPES  */
#define ll long long
# define pair<ll, ll> pll;
//bool vis[1000+1][1000+1];

struct ArrayHasher {
    std::size_t operator()(const std::array<int, 3>& a) const {
        std::size_t h = 0;

        for (auto e : a) {
            h ^= std::hash<int>{}(e)  + 0x9e3779b9 + (h << 6) + (h >> 2); 
        }
        return h;
    }   
};

void solve() {
	ll x, y;
    cin >> x >> y;
    queue<array<int, 3>> q;
    q.push({x, y, 1}); // a, b, steps done
    unordered_map< array<int,3> , int, ArrayHasher > vis;
    while(!q.empty()) {
		array<int, 3> cur = q.front();
		q.pop();
		ll a = cur[0];
		ll b = cur[1];
		ll step = cur[2];
//		cout << a << ", " << b << ", " << step << endl;
		if (vis.find(cur) != vis.end()) {
			continue;
		}
		vis[cur]++;
		if (a - b == 0) {
			cout << (step-1) << "\n";
			return;
		}    	
		if (step % 2 == 1) {
			q.push({a+step, b, step+1});
			q.push({a, b+step, step+1});
		} else {
			q.push({a-step, b, step+1});
			q.push({a, b-step, step+1});
		}
	}
	cout << -1 << "\n";
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