#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;

int main(){

	int n, x; cin >> n >> x;
	vector<int> coins;
	for (int i = 0; i < n; i++) {
		int no; cin >> no;
		coins.push_back(no);
	}

	vector<vector<int>> dp(n + 1, vector<int>(x + 1));

	for (int i = 0; i < n; i++) {
		dp[i][0] = 1;
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int sum = 1; sum <= x; sum++) {
			int skipping = dp[i + 1][sum];
			int picking = 0;
			if (coins[i] <= sum) {
				picking = dp[i][sum - coins[i]];
			}
			dp[i][sum] = (skipping % mod + picking % mod) % mod;
		}
	}

	cout << dp[0][x];

	return 0;

}
