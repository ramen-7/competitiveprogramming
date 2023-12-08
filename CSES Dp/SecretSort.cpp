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


// max k operations, so map 
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int t;
	cin >> t;
	while(t --> 0) {
		int n;
		string inp;
		cin >> n >> inp;
		int ansA = 0;
		int ansB = 0;
		bool check = false;
		for (int x = 1; x <= 20; x++) {
			for (int y = 20-x; y >= 1; y--) {
				int winA = 0;
				int winB = 0;
				int countA = 0;
				int countB = 0;
				for (int i = 0; i < inp.size(); i++) {
					if (inp[i] == 'A') {
						countA++;
					} else if (inp[i] == 'B') {
						countB++;
					}
					if (countA == x) {
						winA++;
						countA = 0;
						countB = 0;
					} else if (countB == x) {
						winB++;
						countA = 0;
						countB = 0;
					} 	
					cout << "x = " << x << ", y = " << y << "winA = " << winA << ", winB = " << winB << endl;
					if (winA == y && ansB == 0) {
						ansA++;
						continue;
					} else if (winB == y && ansA == 0) {
						ansB++;
						continue;
					} else if ((winA == y && ansB > 0) || (winB == y && ansA > 0)){
						check = true;
						break;
					}
				}
				
			}
		}
		cout << "ansA = " << ansA << ", anB = " << ansB << endl;
		if (check) {
			cout << "?\n";
		} else if (ansA > 0) {
			cout << "A\n";
		} else if (ansB > 0) {
			cout << "B\n";
		}
	}
}
