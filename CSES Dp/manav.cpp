#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	string inp;
	getline(cin, inp);
    inp = ' ' + inp;
	for (int i = 0; i < inp.size(); i++) {
	    if (isspace(inp[i]) && i < inp.size()) {
	        cout << inp[i+1];
	        i++;
	    }
	}
}
