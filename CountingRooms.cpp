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
 
	int n, m; cin >> n >> m;
	vector<vector<char>> grid(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char ch; cin >> ch;
			grid[i][j] = ch;
		}
	}
 
	int ans = 0;
 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == '.') {
				ans++;
				queue<pair<int, int>> q;
				q.push({i, j});
				grid[i][j] = '#';
				while(!q.empty()) {
					auto p = q.front();
					q.pop();
					if (p.first + 1 < n && grid[p.first + 1][p.second] == '.') {
						grid[p.first + 1][p.second] = '#';
						q.push({p.first + 1, p.second});
					}
					if (p.first - 1 >= 0 && grid[p.first - 1][p.second] == '.') {
						grid[p.first - 1][p.second] = '#';
						q.push({p.first - 1, p.second});
					}
					if (p.second + 1 < m && grid[p.first][p.second + 1] == '.') {
						grid[p.first][p.second + 1] = '#';
						q.push({p.first, p.second + 1});
					}
					if (p.second - 1 >= 0 && grid[p.first][p.second - 1] == '.') {
						grid[p.first][p.second - 1] = '#';
						q.push({p.first, p.second - 1});
					}
				}
			}
		}
	}
 
	cout << ans;
 
	return 0;
 
}
