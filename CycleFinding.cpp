#include <bits/stdc++.h>
using namespace std;
 
#define int 				long long int
#define endl 				'\n'
 
const int INF = 1e15;
 
int32_t main() {
 
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	int n, m; cin >> n >> m;
	vector<vector<int>> edges;
	int s = -1;
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		edges.push_back({u, v, w});
		if (w < 0) {
			s = u;
		}
		if (u == v && w < 0) {
			cout << "YES\n";
			cout << u << " " << v;
			return 0;
		}
	}
 
	if (s == -1) {
		cout << "NO";
		return 0;
	}
 
	vector<int> distance(n + 1, 1e15);
	vector<int> parent(n + 1, -1);
	distance[s] = 0;
	int x = -1;
	for (int i = 1; i <= n; i++) {
		x = -1;
		for (int i = 0; i < m; i++) {
			int u = edges[i][0];
			int v = edges[i][1];
			int w = edges[i][2];
			if (distance[u] < 1e15 && distance[u] + w < distance[v]) {
				distance[v] = distance[u] + w;
				parent[v] = u;
				x = v;
			}
		}
	}
 
	if (x == -1) {
		cout << "NO";
	} else {
		cout << "YES\n";
		int y = x;
		for (int i = 0; i < n; i++) {
			y = parent[y];
		}
 
		vector<int> path;
		for (int node = y; ; node = parent[node]) {
			path.push_back(node);
			if (node == y && path.size() > 1) {
				break;
			}
		}
 
		for (int i = (int) path.size() - 1; i >= 0; i--) {
			cout << path[i] << " ";
		}
	}
 
	return 0;
 
}
