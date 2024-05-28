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
	int sx = 0, sy = 0, ex = 0, ey = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char ch; cin >> ch;
			grid[i][j] = ch;
			if (ch == 'A') {
				sx = i;
				sy = j;
			}
			if (ch == 'B') {
				ex = i;
				ey = j;
			}
		}
	}
 
	vector<vector<char>> path(n, vector<char>(m, '.'));
	queue<pair<int, int>> q;
	q.push({sx, sy});
	bool flag = false;
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		if (p.first == ex && p.second == ey) {
			flag = true;
			break;
		}
		if (p.first + 1 < n && (grid[p.first + 1][p.second] == '.' || grid[p.first + 1][p.second] == 'B')) {
			grid[p.first + 1][p.second] = '#';
			q.push({p.first + 1, p.second});
			path[p.first + 1][p.second] = 'D';
		}
		if (p.first - 1 >= 0 && (grid[p.first - 1][p.second] == '.' || grid[p.first - 1][p.second] == 'B')) {
			grid[p.first - 1][p.second] = '#';
			q.push({p.first - 1, p.second});
			path[p.first - 1][p.second] = 'U';
		}
		if (p.second + 1 < m && (grid[p.first][p.second + 1] == '.' || grid[p.first][p.second + 1] == 'B')) {
			grid[p.first][p.second + 1] = '#';
			q.push({p.first, p.second + 1});
			path[p.first][p.second + 1] = 'R';
		}
		if (p.second - 1 >= 0 && (grid[p.first][p.second - 1] == '.' || grid[p.first][p.second - 1] == 'B')) {
			grid[p.first][p.second - 1] = '#';
			q.push({p.first, p.second - 1});
			path[p.first][p.second - 1] = 'L';
		}
	}
 
	if (flag == false) {
		cout << "NO";
	} else {
		cout << "YES\n";
		string str = "";
		int i = ex, j = ey;
		while (i != sx || j != sy) {
			str += path[i][j];
			if (path[i][j] == 'D') {
				i--;
			} else if (path[i][j] == 'U') {
				i++;
			} else if (path[i][j] == 'R') {
				j--;
			} else {
				j++;
			}
		}
 
		cout << str.length() << endl;
		for (int i = str.length() - 1; i >= 0; i--) {
			cout << str[i];
		}
	}
 
	return 0;
 
}
