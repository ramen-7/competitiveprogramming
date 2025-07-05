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

// knird, rehtona em barg wehpeN.
// woN! afos siht fo tuo em teG! pleH!
// niaga taerg aciremA ekaM. mih etouq oT: "pmurT tnediserP evol I."
// won, tseb eht era uoY!
// You keep me sleeping — it is still right, there...
// ereht thgir llits si— tI gnipeels em peek, uoY...

vector<string> splitBySpace(string& sentence) {
	vector<string> splitArray;
	string current = "";
	
	for (char c : sentence) {
        if (c == ' ') {                  
            if (!current.empty()) {     
                splitArray.push_back(current);
                current.clear();
            }
        } else {
            current += c;              
        }
    }

    if (!current.empty()) {
        splitArray.push_back(current);
    }

    return splitArray;
}

void solve() {
	string sentence;
	getline(cin, sentence);
	
	  vector<char> punctuation;
  vector<int> punctuationIndex;
  vector<bool> isPunctuationAtStartOfWord;
  
  // get all punctuations, their word's position and their place before or after
  // the word
  
  vector<string> splitSentence = splitBySpace(sentence);
  
  for (int idx = 0; idx < splitSentence.size(); idx++) {
    // get word
    string word = splitSentence[idx];
  
    // if there are multiple punctuations at the start of the word - this allows
    // us to capture that
    bool reachedFirstChar = false;
    for (int i = 0; i < word.size(); i++) {
      if (ispunct(word[i])) {
        // only add that till we dont get the first character of the word
        if (!reachedFirstChar) {
          punctuationIndex.push_back(idx);
          isPunctuationAtStartOfWord.push_back(true);
          punctuation.push_back(word[i]);
        } else {
          punctuationIndex.push_back(idx);
          isPunctuationAtStartOfWord.push_back(false);
          punctuation.push_back(word[i]);
        }
      } else {
        reachedFirstChar = true;
      }
    }
  }
  
  // now that we have the original positions of the punctuations, let's get the
  // original sentence reversed since uncle speaks in reverse
  reverse(sentence.begin(), sentence.end());
  
  vector<string> reverseSplitSentence = splitBySpace(sentence);
  
  string ans = "";
  int puncIdx = 0;
  
  for (int idx = 0; idx < reverseSplitSentence.size(); idx++) {
    string word = reverseSplitSentence[idx];
    string originalWord = "";
    for (char c : word) {
      if (!ispunct(c)) {
        originalWord += c;
      }
    }
    
    while (puncIdx < punctuationIndex.size() &&
           punctuationIndex[puncIdx] == idx &&
           isPunctuationAtStartOfWord[puncIdx]) {
      originalWord = punctuation[puncIdx] + originalWord;
      puncIdx++;
    }
    while (puncIdx < punctuationIndex.size() &&
           punctuationIndex[puncIdx] == idx &&
           !isPunctuationAtStartOfWord[puncIdx]) {
      originalWord += punctuation[puncIdx];
      puncIdx++;
    }
    ans = ans + originalWord + " ";
  }
  
  if (!ans.empty()) {
    ans.pop_back();
  }
   	
	cout << ans << '\n';
} 


int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    ll t;
//    cin >> t;
//    while (t-- > 0) {
    	solve();		
//	}
}


