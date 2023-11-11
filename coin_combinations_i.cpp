#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

#define int long long int

const int mod = 1e9 + 7;

int32_t main(){

	int n, x; cin >> n >> x;
	vector<int> coins;
	for (int i = 0; i < n; i++) {
		int no; cin >> no;
		coins.push_back(no);
	}
	sort(coins.begin(), coins.end());

	vector<int> dp(1000005, 0);
	dp[0] = 1;
	for (int i = 1; i <= x; i++) {
		int y = 0;
		for (int j = 0; j < n; j++) {
			if (coins[j] > i) {
				break;
			}
			y = (y % mod + dp[i - coins[j]] % mod) % mod;
		}

		dp[i] = y;
	}

	cout << dp[x];

	return 0;

}
