#include <bits/stdc++.h>
using namespace std;
 
#define int 				long long int
#define endl 				'\n'
#define vi 					vector<int>
#define pi 					pair<int, int>
#define ff 					first
#define ss 					second
#define pb 					push_back
#define mp 					make_pair
#define rep(i, a, b) 		for (int i = a; i <= b; i++)
 
int32_t main() {
 
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	int n; cin >> n;
	int cs = 0, ms = LLONG_MIN;
	rep(i, 1, n) {
		int no; cin >> no;
		cs += no;
		ms = max(ms, cs);
		if (cs < 0) {
			cs = 0;
		}
	}
 
	cout << ms;
 
	return 0;
 
}
