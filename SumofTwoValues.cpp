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
 
	int n, sum; cin >> n >> sum;
	vector<pi> v;
	rep(i, 1, n) {
		int no; cin >> no;
		v.pb({no, i});
	}
	sort(v.begin(), v.end());
	int i = 0, j = n - 1;
	while (i < j) {
		int x = v[i].ff + v[j].ff;
		if (x == sum) {
			cout << v[i].ss << " " << v[j].ss;
			return 0;
		} else if (x < sum) {
			i++;
		} else {
			j--;
		}
	}
 
	cout << "IMPOSSIBLE";
 
	return 0;
 
}
