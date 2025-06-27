#include <bits/stdc++.h>
using namespace std;


/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

/* FUNCTIONS */
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back

/* PRINTS */
template <class T>

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
const char enl= '\n';
/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

struct compare {
	bool operator()(const pair<ll, ll>& a, const pair<ll, ll>& b) {
		if (a.first == b.first) {
			// ascending
			return a.second > b.second;
		}
		// descending
		return a.first < b.first;
	}
};

void solve() {
    ll k, a, b, x, y;
    cin >> k >> a >> b >> x >> y;
    ll ans = 0;

    // Scenario 1
    ll current_k_s1 = k; 
    ll count_a_s1 = 0;
    if (current_k_s1 >= a) {
        count_a_s1 = (current_k_s1 - a) / x + 1;
        current_k_s1 -= count_a_s1 * x;
    }

    ll count_b_s1 = 0;
    if (current_k_s1 >= b) {
        count_b_s1 = (current_k_s1 - b) / y + 1;
    }
    ans = max(ans, count_a_s1 + count_b_s1);

    // Scenario 2
    ll current_k_s2 = k; 
    ll count_b_s2 = 0;
    if (current_k_s2 >= b) {
        count_b_s2 = (current_k_s2 - b) / y + 1;
        current_k_s2 -= count_b_s2 * y;
    }

    ll count_a_s2 = 0;
    if (current_k_s2 >= a) {
        count_a_s2 = (current_k_s2 - a) / x + 1;
    }
    ans = max(ans, count_b_s2 + count_a_s2);

    cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t-- > 0) {
    	solve();		
	}
}


