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

	int n, m; cin >> n >> m;
	map<int, int> m1;
	for (int i = 0; i < n; i++) {
		int no; cin >> no;
		m1[no]++;
	}

	for (int i = 0; i < m; i++) {
		int no; cin >> no;
		auto it = m1.upper_bound(no);
		if (it == m1.begin()) {
			cout << -1 << endl;
		} else {
			it--;
			cout << it->first << endl;
			it->second--;
			if (it->second == 0) {
				m1.erase(it);
			}
		}
	}

	return 0;

}
