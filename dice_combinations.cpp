#include <bits/stdc++.h>
using namespace std;

#define int long long int

const int mod = 1e9 + 7;

int32_t main(){

	int n; cin>>n;
	vector<int> dp;
	dp.push_back(1);
	for(int i = 1; i <= 6; i++) {
		int sum = 0;
		for (int j = 0; j < i; j++) {
			sum += dp[j];
		}
		dp.push_back(sum);
	}

	if (n <= 6) {
		cout << dp[n];
		return 0;
	}

	for (int i = 7; i <= n; i++) {
		int sum = 0;
		sum += (dp[1] % mod + dp[2] % mod + dp[3] % mod + dp[4] % mod + dp[5] % mod + dp[6] % mod) % mod;
		dp[1] = dp[2];
		dp[2] = dp[3];
		dp[3] = dp[4];
		dp[4] = dp[5];
		dp[5] = dp[6];
		dp[6] = sum;
	}

	cout << dp[6];

	return 0;

}
