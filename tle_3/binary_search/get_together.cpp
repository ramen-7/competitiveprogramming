#include <bits/stdc++.h>
#include <iomanip>
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
#define MOD 1000000007
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
string llToBinaryString(ll n, int bits) {
    string s;
    for (int i = bits - 1; i >= 0; --i)
        s += (n & (1LL << i)) ? '1' : '0';
    return s;
}
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

bool is_possible(double t, vector<pair<double, double>>& arr, ll n) {
    pair<double, double> cur = {-1e18, 1e18};
    for (pair<double, double> p: arr) {
        double x_i = p.first;
        double v_i = p.second;

        double cur_left = x_i - (t*v_i);
        double cur_right = x_i + (t*v_i);

        pair<double, double> range = {cur_left, cur_right};

        cur = {max(cur.first, range.first), min(cur.second, range.second)};

        if (cur.first > cur.second) {
            return false;
        }
    }
    
    return true;
}

void solve() {
    ll n;
    cin >> n;
    vector<pair<double, double>> arr(n);
    for (int i = 0; i < n; i++) {
        // pll cur;
        cin >> arr[i].first >> arr[i].second;
    }
    // 1e-6 precision, range is upto 1e9 - log2(1e15) ~ 50 iterations
    double l = 0, r = 1e9;
    for (int iter = 0; iter < 60; iter += 1) {
        double mid = (l + r)/2;
        if (is_possible(mid, arr, n)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << setprecision(7) << fixed << r << '\n';
}


int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    // cin >> t;
    // while (t-- > 0) {
    	solve();		
	// }
}


