// C++ program to demonstrate the 
// ordered set in GNU C++ 
#include <iostream> 
using namespace std; 
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ordered_set = tree<pair<int, int>, null_type, std::less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;
 
 
void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	ordered_set s; 
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < k; i++) {
		s.insert({arr[i], i});
	}
	for (int i = k-1; i < n; i++) {
		int med = s.find_by_order((k-1)/2)->first;
		if (i != n-1) {
			s.erase(s.lower_bound({arr[i-k+1], 0})); // {first elemenet, can be any variable x (doesn't matter)}
			s.insert({arr[i+1], i});
		}
		cout << med << " ";
	}
}
 
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	solve();
	
}
 
 
