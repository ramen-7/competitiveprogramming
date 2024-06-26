#include <bits/stdc++.h>
using namespace std;

/* clang-format off */

/* TYPES  */
#define F first
#define S second
#define vec vector
#define pb push_back
#define pdd pair<ld, ld>
#define all(m) m.begin(), m.end()
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define usi unordered_set<int>
#define usll unordered_set<long long>

/* FUNCTIONS */
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back

/* PRINTS */
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }

/* UTILS */
//#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
void print_arr(int a[], int size) { for (int i=0; i<size; i++) cout << a[i] << " ";}
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
const char enl = '\n';
ll INF = 1e16;
/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

typedef array<ll, 3> P;

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<vector<pll>> adj(n);
	for (int i = 0; i < m; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		--u;
		--v;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	vector<ll> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	
	vector<vector<ll>> dist(n, vector<ll>(n, INF));
	vector<vector<bool>> visited(n, vector<bool>(n, false));

	
	
//	ans[0] = 0;
	dist[0][0] = 0;
//	visited[0][0] = true;
	
	priority_queue<P, vector<P>, greater<P>> pq;
	pq.push({0, 0, 0}); // cost , node, bike idx
	
	while (!pq.empty()) {
		P cur = pq.top();
		pq.pop();
		
		ll cur_city = cur[1];
		ll cur_cost = cur[0];
		ll cur_bike = cur[2];
		
//		cout << "cur city = " << cur_city << ", cur cost = " << cur_cost << ", cur bike = " << cur_bike << enl;
		
		if (cur_city == n-1) {
			cout << dist[cur_city][cur_bike] << enl;
			return;
		}
		
		if (visited[cur_city][cur_bike]) {
			continue;
		}
		visited[cur_city][cur_bike] = true;
		
		for (auto [nbr, nbr_cost]: adj[cur_city]) {
//			ll nbr = n.first;
//			ll nbr_cost = n.second;
			ll new_bike = cur_bike;
			
			if (s[cur_bike] > s[nbr]) {
				new_bike = nbr;
			}
			
			// if dist to reach nbr on new_bike (which could be the old one)
			// is more than dist to reach cur city on cur bike + cost to reach nbr on cur_bike
			if (dist[nbr][new_bike] > dist[cur_city][cur_bike] + s[new_bike]*nbr_cost) {
				dist[nbr][new_bike] = dist[cur_city][cur_bike] + s[new_bike]*nbr_cost;
				pq.push({dist[nbr][new_bike], nbr, new_bike});
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
    while (t --> 0) {
    	solve();
	}
}