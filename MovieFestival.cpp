#include <bits/stdc++.h>
using namespace std;

#define int 				long long int
#define endl 				'\n'

bool compare(pair<int, int> &p1, pair<int, int> &p2) {
	return p1.second < p2.second;
}

int32_t main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v.push_back({a, b});
	}

	sort(v.begin(), v.end(), compare);

	int count = 1;
	int e = v[0].second;
	for (int i = 1; i < n; i++) {
		if (v[i].first >= e) {
			e = v[i].second;
			count++;
		}
	}

	cout << count;

	return 0;

}
