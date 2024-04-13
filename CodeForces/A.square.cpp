#include <bits/stdc++.h>
using namespace std;

/* clang-format off */

/* TYPES  */
#define F first
#define S second
#define vec vector
#define pb push_back
#define pll pair<ll, ll>
#define pdd pair<ld, ld>
#define all(m) m.begin(), m.end()
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define usi unordered_set<int>
#define usll unordered_set<long long>
const char enl = '\n';

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

/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;


void solve() {
	ll n, p, k, s, t;
	cin >> n >> p >> k >> s >> t;
//	s--;
//	t--;
//	cout << "here" << endl;
//	vector<vector<ll>> adj(n+1);
	vector<ll> studentBuildings(k);
	vector<vector<bool>> path(n+1, vector<bool>(n+1, false));
	for (int i = 0; i < k; i++) {
		cin >> studentBuildings[i];
	}
//	cout << "here" << endl;
//	for (int i: studentBuildings) {
//		cout << i;
//	}
//	cout << endl;
	for (int i = 0; i < p; i++) {
		ll u, v;
		cin >> u >> v;
//		--u;
//		--v;
//		adj[u].push_back(v);
//		adj[v].push_back(u);
		path[u][v] = true;
		path[v][u] = true;
	}
//	cout << "here" << endl;
	vector<ll> distS(n+1, -1);
	vector<ll> distT(n+1, -1);
	ll level = -1;
//	distS[s] = 0;
//	cout << "here" << endl;
	queue<ll> q;
	q.push(s);
	while(!q.empty()) {
		level++;
		int size = q.size();
		for (int i = 0; i < size; i++) {
			ll cur = q.front();
			q.pop();
			if (distS[cur] != -1) {
				continue;
			}
			distS[cur] = level;
			for (int nbr = 1; nbr <= n; nbr++) {
//				cout << path[cur][nbr] << " ";
				if (path[cur][nbr]) {
					q.push(nbr);	
				}
//				cout << endl;
			}	
		}		
	}
//	q.clear();
	q.push(t);
	level = -1;
	while(!q.empty()) {
		level++;
		int size = q.size();
		for (int i = 0; i < size; i++) {
			ll cur = q.front();
			q.pop();
			if (distT[cur] != -1) {
				continue;
			}
			distT[cur] = level;
			for (int nbr = 1; nbr <= n; nbr++) {
				if (path[cur][nbr]) {
					q.push(nbr);	
				}
			}				
		}
	}
	for (int i: distS) {
		cout << i << " ";
	}
	cout << endl;
	for (int i: distT) {
		cout << i << " ";
	}
	cout << endl;
	unordered_map<string, vector<ll>> hmap;
	for (int i= 1; i <= n; i++) {
		string key = to_string(distS[i]) + "_" + to_string(distT[i]);
		hmap[key].push_back(i);
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		if (distT[i] == distS[i]) {
			continue;
		}
		string opp = to_string(distT[i]) + "_" + to_string(distS[i]); 
		if (hmap.find(opp) != hmap.end()) {
			vector<ll> nodes = hmap[opp];
			for (ll node: nodes) {
				if (!path[i][node]) {
//					cout << i << ", " << node << " for " << opp << endl;
					ans++;
					path[i][node] = true;
					path[node][i] = true;
				}
			}
		}
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
    	solve();
	}
}