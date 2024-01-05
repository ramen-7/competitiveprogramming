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

/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

void solve(vector<vector<pll>>& adj, vector<ll>& s, int n) {
	
	vector<vector<ll>> dist(n, vector<ll>(1001, LONG_MAX));
	vector<vector<bool>> visited(n, vector<bool>(1001, false));
	priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> pq;
	dist[0][0] = 0;
	pq.push({0, 0, 0});
		
	while (!pq.empty()) {
		ll city = pq.top()[1];
		ll bike = pq.top()[2];
		pq.pop();
		
		if (city == n-1) {
			cout << dist[city][bike] << enl;
			return;
		}
		
		// if we have already visited this city on this bike
		if (visited[city][bike]) {
			continue;
		}
		visited[city][bike] = true;
		
		for (auto neigh: adj[city]) {
			ll nbr = neigh.second;
			ll cost = neigh.first;
			
			ll newBike = bike;
			if (s[nbr] < s[bike]) {
				newBike = nbr;
			}
			
			// if OLD dist of nbr on newbike is less than dist of current city
			// on current bike + cost of reaching the cur city on cur bike
			if (dist[nbr][newBike] > dist[city][bike] + cost*s[bike]) {
				dist[nbr][newBike] = dist[city][bike] + cost*s[bike];
				pq.push({dist[nbr][newBike], nbr, newBike});
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
    	ll n, m;
    	cin >> n >> m;
    	vector<vector<pll>> adj(n);
    	for (int i = 0; i < m; i++) {
    		ll u, v, w;
    		cin >> u >> v >> w;
    		adj[u-1].push_back({w, v-1}); // {cost and n}
    		adj[v-1].push_back({w, u-1});
		}
		vector<ll> s(n);
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
		solve(adj, s, n);
		
	}
}