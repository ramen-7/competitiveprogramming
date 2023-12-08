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

 
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // 'a' represented by 1, 'b' represented by 2, 'null' represented by 3
    // we use a adjacency matrix to represent a the NFA.
    
    
    // Q1. Generating NFA using thompson construction
    
    // this a directed graph 
    int n = 11;
    vector<vector<int>> thompson(n, vector<int> (n));
    thompson[0][1] = 3; // initial node has a null to 1.
    thompson[1][2] = 3;
    thompson[1][4] = 3;
    thompson[2][3] = 1;
    thompson[4][5] = 2;
    thompson[3][6] = 3;
    thompson[5][6] = 3;
    thompson[6][1] = 3;
    thompson[0][7] = 3;
    thompson[6][7] = 3;
    thompson[7][8] = 1;
    thompson[8][9] = 2;
    thompson[9][10] = 2;
    
    
    cout << "The Thompson Construction is as follows: " << endl;
    cout << "       ";
    for (int i = 0; i < n; i++) {
    	cout << i << " ";
	}
	cout << endl;
    for (int i = 0; i < n; i++) {
    	cout << "i = " << i << ": ";
    	for (int j = 0; j < n; j++) {
    		cout << thompson[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << endl << endl << "-------------" << endl << endl;
	//Generating the DFA using subset construction
	map<int, set<int>> null_closure;
	for (int i = 0; i < n; i++) {
		// we start with a node and explore all those neighbors
		// of this node that have a null connection
		set<int> seen;
		queue<int> q;
		q.push(i);
		while(!q.empty()) {
			int curNode = q.front();
			seen.insert(curNode);
			q.pop();
			for (int j = 0; j < n; j++) {
				// if any connections are null
				if (thompson[curNode][j] == 3) {
					q.push(j);
					seen.insert(j);
				}
			}
		}
		null_closure[i] = seen;
	}
	
	for (const auto& entry : null_closure) {
        int key = entry.first;
        const set<int>& values = entry.second;

        cout << "Null closure of " << key << ": ";
        
        for (const int& value : values) {
            cout << value << " ";
        }

        cout << endl;
    }
    
    cout << endl << endl << "-------------" << endl << endl;
    // checking if the inserted string ends with only 'abb' and belongs
    // to the RE
    
    cout << "Please enter the number of testcases: " << endl;
    int t;
    cin >> t;
    while (t --> 0) {
    	cout << "Please insert a string with only characters being 'a' and 'b'" << endl;
		string inp;
		cin >> inp;	
//		cout << characters.size() << endl;
		int size = inp.size();
		unordered_set<char> characters;
		for (int i = 0; i < size; i++) {
			characters.insert(inp[i]);
		}
		bool flag = false;
		if (characters.size() > 2 || size < 3) {
			flag = true;
		}
		if (!flag) {
			if (inp.substr(size - 3) != "abb") {
				flag = true;
			}
		}
		if (!flag) {
			cout << "accepted" << endl;
		} else {
			cout << "rejected" << endl;
		}
	}
}