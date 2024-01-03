#include <bits/stdc++.h>
using namespace std;

/* clang-format off */

/* TYPES  */
#define ll long long
#define pii pair<ll, ll>
#define pll pair<long long, long long>
#define vi vector<ll>
#define vll vector<long long>
#define mii map<ll, ll>
#define si set<ll>
#define sc set<char>

/* FUNCTIONS */
#define f(i,s,e) for(long long ll i=s;i<e;i++)
#define cf(i,s,e) for(long long ll i=s;i<=e;i++)
#define rf(i,e,s) for(long long ll i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back
const char enl = '\n';
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }

//struct custom_hash {
//    static ull64_t splitmix64(ull64_t x) {
//        // http://xorshift.di.unimi.it/splitmix64.c
//        x += 0x9e3779b97f4a7c15;
//        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//        return x ^ (x >> 31);
//    }
//
//    size_t operator()(ull64_t x) const {
//        static const ull64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//        return splitmix64(x + FIXED_RANDOM);
//    }
//};

/* PRllS */
template <class T>
void prll_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }
bool prime(long long a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

/* UTILS */
//#define PI 3.1415926535897932384626433832795

long long primeFactors(long long n) 
{ 
	vector<long long> factors;
    // Print the number of 2s that divide n 
    while (n % 2 == 0) 
    { 
        
        return 2;
        n = n/2; 
    } 
 
    // n must be odd at this point. So we can skip 
    // one element (Note i = i +2) 
    for (int i = 3; i <= sqrt(n); i = i + 2) 
    { 
        // While i divides n, print i and divide n 
        while (n % i == 0) 
        { 
            return i;
            n = n/i; 
        } 
    } 
 
    // This condition is to handle the case when n 
    // is a prime number greater than 2 
    return n;
} 


 
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t;
    cin >> t;
    while (t --> 0) {
    	long long a, b, x;
    	cin >> a >> b;
    	if (a == 1 && prime(b)) {
    		cout << b*b*1LL << enl;
    		continue;
		} else if (prime(a) && prime(b)) {
			cout << a*b*1LL << enl;
			continue;
		}else {
			long long g = gcd(a, b);
			long long product = b;
			int iter = 0;
			while (true && iter < 10) {
				product *= g;
//				cout << product << endl;
				if (product % b == 0) {
					break;
				}
				iter++;
			}
			cout << product << enl;
		}
		
	}
}