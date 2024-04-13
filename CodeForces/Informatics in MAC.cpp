#include <bits/stdc++.h>
using namespace std;

/* clang-format off */
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
const char enl= '\n';
/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;


void solve() {
	ll n;
	cin >> n;
	vector<ll> arr(n);
	unordered_map<ll, ll, custom_hash> seen;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
		
	ll mex = 0;
	
	for (int i: arr) {
		seen[i]++;
		while (true) {
			if (seen.find(mex) != seen.end()) {
				mex++;
			} else {
				break;
			}
		}
	}
	
//	cout << "mex is " << mex << endl;
	unordered_map<ll, ll, custom_hash> seen2;
	ll mex2 = 0;
	for (int i = n-1; i >= 0; i--) {
		seen2[arr[i]]++;
		seen[arr[i]]--;
		if (arr[i] < mex && seen[arr[i]] == 0) {
			cout << -1 << "\n";
			return;
		} 
		while (true) {
			if (seen2.find(mex2) != seen2.end()) {
				mex2++;
			} else {
				break;
			}
		}
//		cout << "mex2 is " << mex2 << endl;
		if (mex == mex2) {
			cout << 2 << "\n";
			cout << 1 << " " << (i) << "\n";
			cout << (i+1) << " " << n << "\n";
			return;
		}
	}
//	if (mex == mex2) {
//		cout << 2 << "\n";
//		cout << 1 << " " << 1 << "\n";
//		cout << 2 << " " << n << "\n";
//		return;
//	}
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

