#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef array<ll, 3> P;
typedef pair<ll, ll> pll;

long long INF = 1e16;

const char enl = '\n';

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    cin >> n >> m;
    
    vector<vector<pll>> adj(n);
    vector<ll> dist(n, INF);
    vector<bool> visited(n, false);
    for (int i = 0; i < m; i++) {
    	ll u, v, w;
    	cin >> u >> v >> w;
    	--u;
    	--v;
    	adj[u].push_back({v, w});
    	adj[v].push_back({u, w});
	}
	
	priority_queue<P, vector<P>, greater<P>> pq;
	pq.push({0, 0, 0});
	dist[0] = 0;
	vector<ll> ans(n, -1);
	
	bool check = false;
	while(!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		
		ll came_from = cur[2];
		ll cur_node = cur[1];
		ll cur_cost = cur[0];
		
		
		if (cur_node == n-1) {
			check = true;
			break;
		}
		
		if (visited[cur_node]) {
			continue;
		}

		visited[cur_node] = true;
		
		
		for (auto nbrs: adj[cur_node]) {
			ll nbr = nbrs.first;
			ll nbrCost = nbrs.second;
			
			if (dist[nbr] > dist[cur_node] + nbrCost) {
//				cout << dist[nbr] << ", " << dist[cur_node] + nbrCost << enl;
				ans[nbr] = cur_node;
//				cout << cur_node << "->" << nbr << endl;
				dist[nbr] = dist[cur_node] + nbrCost;
				pq.push({dist[nbr], nbr, cur_node});
			}
		}
	}
	
	if (!check) {
		cout << -1 << endl;
		return 0;
	}
	vector<ll> p;
	int cur = n-1;
	while (cur != 0) {
		p.push_back(cur+1);
		cur = ans[cur];
	}
	cout << 1 << " ";
	reverse(p.begin(), p.end());
	for (int i: p) {
		cout << i << " ";
	}
} 