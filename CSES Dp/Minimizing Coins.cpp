#include <bits/stdc++.h>
using namespace std;
 
/* clang-format off */
 
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
# define MOD 1
#define PI 3.1415926535897932384626433832795
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
 
 
/* clang-format on */
int n, x;
int arr[100];
const int maxX = 10e6;
int dp[maxX + 1];
 
int solve(int i, ll target){
	if(i >= n || target < 0){
		return INT_MAX;
	}
	
	if((target - arr[i]) == 0){
		return 1;
	}
	
	if(dp[target] != -1){
		return dp[target];
	}
	
	ll taken = INT_MAX;
	if((target - arr[i]) >= 0){
		taken = 0;
		taken = 1 + solve(i, target-arr[i]);
	}
	ll not_taken = solve(i+1, target);
	if(taken < 0){
		taken = INT_MAX;
	}
	if(not_taken < 0){
		not_taken = INT_MAX;
	}
//	cout << taken << ", " << not_taken << endl;
	return dp[target] = min(taken, not_taken);
}
 
/* Main()  function */
 
int main()
{
	cin >> n >> x;
	for(int i = 0; i < n; i++)
		cin>> arr[i];
	memset(dp, -1, sizeof(dp));
	ll ans = solve(0, x);
	if(ans == INT_MAX){
		cout << -1 << endl;
	}
	else{
		cout << ans << endl;
	}
}