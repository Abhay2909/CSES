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

	int n, m, k; cin >> n >> m >> k;
	vector<int> v1, v2;
	for (int i = 0; i < n; i++) {
		int no; cin >> no;
		v1.push_back(no);
	}

	for (int i = 0; i < m; i++) {
		int no; cin >> no;
		v2.push_back(no);
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	int count = 0;
	int i = 0, j = 0;
	while (i < n && j < m) {
		if (abs(v2[j] - v1[i]) <= k) {
			count++;
			i++;
			j++;
		} else if (v2[j] > v1[i]) {
			i++;
		} else {
			j++;
		}
	}

	cout << count;

	return 0;

}
