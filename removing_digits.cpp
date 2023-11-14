#include <iostream>
#include <cstring>
#include <set>
#include <climits>
using namespace std;

int main(){

	int n; cin >> n;
	int dp[1000005];
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;

	set<int> digits;

	for (int i = 1; i <= n; i++) {
		digits.clear();
		int x = i;
		while (x) {
			digits.insert(x % 10);
			x /= 10;
		}

		int ans = INT_MAX;
		for (int digit : digits) {
			if (digit <= i && dp[i - digit] != -1) {
				ans = min(ans, dp[i - digit] + 1);
			}
		}
		if (ans == INT_MAX) {
			ans = -1;
		}
		dp[i] = ans;
	}

	cout << dp[n];

	return 0;

}
