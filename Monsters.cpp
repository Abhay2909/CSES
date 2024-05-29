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
	queue<pair<int, int>> q;
	int x = -1, y = -1;
	vector<vector<char>> grid(n, vector<char>(m));
	vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 'M') {
				q.push({i, j});
				dist[i][j] = 0;
			}
			if (grid[i][j] == 'A') {
				x = i;
				y = j;
			}
		}
	}
 
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		int i = p.first, j = p.second;
		if (i + 1 < n && grid[i + 1][j] != '#' && dist[i + 1][j] == INT_MAX) {
			q.push({i + 1, j});
			dist[i + 1][j] = dist[i][j] + 1;
		}
		if (i - 1 >= 0 && grid[i - 1][j] != '#' && dist[i - 1][j] == INT_MAX) {
			q.push({i - 1, j});
			dist[i - 1][j] = dist[i][j] + 1;
		}
		if (j + 1 < m && grid[i][j + 1] != '#' && dist[i][j + 1] == INT_MAX) {
			q.push({i, j + 1});
			dist[i][j + 1] = dist[i][j] + 1;
		}
		if (j - 1 >= 0 && grid[i][j - 1] != '#' && dist[i][j - 1] == INT_MAX) {
			q.push({i, j - 1});
			dist[i][j - 1] = dist[i][j] + 1;
		}
	}
 
	q.push({x, y});
	vector<vector<char>> path(n, vector<char>(m, '#'));
	vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
	path[x][y] = 'A';
	distance[x][y] = 0;
	grid[x][y] = '#';
	int x1 = -1, y1 = -1;
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		int i = p.first, j = p.second;
		if (i == n - 1 || i == 0 || j == m - 1 || j == 0) {
			x1 = i;
			y1 = j;
			break;
		}
 
		if (i + 1 < n && grid[i + 1][j] != '#' && dist[i + 1][j] > distance[i][j] + 1) {
			path[i + 1][j] = 'D';
			grid[i + 1][j] = '#';
			distance[i + 1][j] = distance[i][j] + 1;
			q.push({i + 1, j});
		}
		if (i - 1 >= 0 && grid[i - 1][j] != '#' && dist[i - 1][j] > distance[i][j] + 1) {
			path[i - 1][j] = 'U';
			grid[i - 1][j] = '#';
			distance[i - 1][j] = distance[i][j] + 1;
			q.push({i - 1, j});
		}
		if (j + 1 < m && grid[i][j + 1] != '#' && dist[i][j + 1] > distance[i][j] + 1) {
			path[i][j + 1] = 'R';
			grid[i][j + 1] = '#';
			distance[i][j + 1] = distance[i][j] + 1;
			q.push({i, j + 1});
		}
		if (j - 1 >= 0 && grid[i][j - 1] != '#' && dist[i][j - 1] > distance[i][j] + 1) {
			path[i][j - 1] = 'L';
			grid[i][j - 1] = '#';
			distance[i][j - 1] = distance[i][j] + 1;
			q.push({i, j - 1});
		}
	}
 
	if (x1 != -1 && y1 != -1) {
		cout << "YES\n";
		vector<char> v1;
		while (path[x1][y1] != 'A') {
			v1.push_back(path[x1][y1]);
			if (path[x1][y1] == 'D') {
				x1--;
			} else if (path[x1][y1] == 'U') {
				x1++;
			} else if (path[x1][y1] == 'L') {
				y1++;
			} else if (path[x1][y1] == 'R') {
				y1--;
			}
		}
		cout << v1.size() << endl;
		for (int i = (int) v1.size() - 1; i >= 0; i--) {
			cout << v1[i];
		}
	} else {
		cout << "NO";
	}
 
	return 0;
 
}
