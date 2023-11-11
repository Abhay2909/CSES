#include <bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main(){

	int n, x; cin >> n >> x;
	vector<int> coins;
	for (int i = 0; i < n; i++) {
		int no; cin >> no;
		coins.push_back(no);
	}
	sort(coins.begin(), coins.end());

	int dp[1000005] = {0};
	for (int i = 1; i <= x; i++) {
		int y = INT_MAX;
		for (int j = 0; j < n; j++) {
			if (coins[j] <= i) {
				if (dp[i - coins[j]] == -1) {
					continue;
				}
				y = min(y, dp[i - coins[j]] + 1);
			} else {
				break;
			}
		}
		if (y == INT_MAX) {
			y = -1;
		}
		dp[i] = y;
		// cout << i << " " << dp[i] << '\n';
	}

	cout << dp[x];

	return 0;

}
