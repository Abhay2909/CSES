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
 
	int n, m, q; cin >> n >> m >> q;
	vector<vector<int>> matrix(n + 1, vector<int>(n + 1, 1e15));
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		matrix[a][b] = min(matrix[a][b], c);
		matrix[b][a] = min(matrix[b][a], c);
	}
 
	for (int i = 1; i <= n; i++) {
		matrix[i][i] = 0;
	}
 
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (matrix[i][j] > matrix[i][k] + matrix[k][j]) {
					matrix[i][j] = matrix[i][k] + matrix[k][j];
				}
			}
		}
	}
 
	for (int i = 1; i <= q; i++) {
		int a, b; cin >> a >> b;
		cout << (matrix[a][b] == 1e15 ? -1 : matrix[a][b]) << endl;
	}
 
	return 0;
 
}
