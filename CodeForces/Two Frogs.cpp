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

bool isPossible(ll lim, vector<ll>& arr, ll n, ll x, ll a, ll y, ll b, ll k, ll LCM) {
	ll total = 0;
	ll idx = n-1;
	ll big, small, bigP, smallP;
	if (x > y) {
		big = x;
		bigP = a;
		small = y;
		smallP = b;
	} else {
		big = y;
		bigP = b;
		small = x;
		smallP = a;
	}
	
	ll countLCM = lim/LCM;
	ll countBig = (lim/bigP) - countLCM;
	ll countSmall = (lim/smallP) - countLCM;
	
//	cout << countLCM << endl;
	
	while (idx >= 0 && countLCM > 0 && lim > 0) {
		total += (arr[idx--]/100) * (x+y);
		countLCM--;
		lim--;
	}
	
//	cout << "afterLCM = " << total << endl;
	
	while (idx >= 0 && countBig > 0 && lim > 0) {
		total += (arr[idx--]/100) * (big);
		countBig--;
		lim--;
	}
	
//	cout << "afterBig = " << total << endl;
	
	while (idx >= 0 && countSmall > 0 && lim > 0) {
		total += (arr[idx--]/100) * (small);
		countSmall--;
		lim--;
	}
	
//	cout << "afterSmall = " << total << endl;
	
	return total >= k;
}

void solve() {
	ll n, a, b;
	cin >> n >> a >> b;
	if (abs(a-b) % 2 == 0) {
		yes();
	} else {
		no();
	}
}



int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t --> 0) {
    	solve();	
	}
}


