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

	int n, x; cin >> n >> x;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int no; cin >> no;
		v.push_back(no);
	}
	sort(v.begin(), v.end());

	int count = 0;

	int i = 0, j = n - 1;
	while (i <= j) {
		if (v[i] + v[j] <= x) {
			count++;
			i++;
			j--;
		} else {
			count++;
			j--;
		}
	}

	cout << count;

	return 0;

}
