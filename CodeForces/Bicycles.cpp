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

/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

bool solve(vector<ll>& arr) {
	unordered_set<ll> seen;
    	ll preOdd = 0;
    	ll preEve = 0;
    	for (int i = 0; i < arr.size(); i++)  {
    		if (i % 2 == 0) {
    			preEve += arr[i];
			} else {
				preOdd += arr[i];
			}
			ll dif = preEve - preOdd;
			if (dif == 0 || seen.find(dif) != seen.end()) {
				return true;
			}
			seen.insert(dif);
		}
	return false;
}
 
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t --> 0) {
    	int n, m;
    	cin >> n >> m;
    	vector<vector<pii>> adj(n);
    	for (int i = 0; i < m; i++) {
    		int u, v, w;
    		cin >> u >> v >> w;
    		adj[u-1].push_back({w, v-1}); // {cost and n}
		}
		vector<int> bike(n);
		for (int i = 0; i < n; i++) {
			cin >> bike[i];
		}
		for (int i = 0; i < n; i++) {
			vector<pii> neighs = adj[i];
			for (int j = 0; j < neighs.size(); j++) {
				auto cur_pair = adj[i][j];
				int new_weight = cur_pair.first * bike[i];
				adj[i][j] = {new_weight, cur_pair.second};
			}
		}
		for (int i = 0; i < n; i++) {
			vector<pii> neighs = adj[i];
			cout << "v = " << i << ": ";
			for (int j = 0; j < neighs.size(); j++) { 
				auto cur_pair = adj[i][j];
				cout << "(" << cur_pair.second << ", " << cur_pair.first << ")";
			}
			cout << endl;
		}
		vector<int> ans(n, INT_MAX);
		priority_queue<pii, vector<pii>, greater<pii>> pq;
		pq.push({0, 0});
		while (!pq.empty()) {
			auto cur_pair = pq.top();
			pq.pop();
            int cur_dist = cur_pair.first;
            int cur_node = cur_pair.second;
            for (int i = 0; i < adj[cur_node].size(); i++) {
                int neigh = adj[cur_node][i].second;
                int neigh_dist = adj[cur_node][i].first;
                int new_dist = neigh_dist + cur_dist;
                if (new_dist < ans[neigh]) {
                    ans[neigh] = new_dist;
                    pq.push({new_dist, neigh});
                }
            }
		}
//		cout << ans[n-1] << "\n";
	}
}