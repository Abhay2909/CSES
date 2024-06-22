#include <bits/stdc++.h>
using namespace std;

#define int 				long long int
#define endl 				'\n'

int32_t main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		m[a]++;
		m[b + 1]--;
	}

	int ans = 0;
	int count = 0;
	for (auto p : m) {
		count += p.second;
		ans = max(ans, count);
	}

	cout << ans;

	return 0;

}
