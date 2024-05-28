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
	unordered_map<int, vector<int>> graph;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
 
	bool flag = true;
	vector<int> visited(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			queue<int> q;
			q.push(i);
			while (!q.empty()) {
				int node = q.front();
				q.pop();
				for (int nbr : graph[node]) {
					if (visited[nbr] == 0) {
						visited[nbr] = 3 - visited[node];
						q.push(nbr);
					} else if (visited[nbr] == visited[node]) {
						flag = false;
						break;
					}
				}
			}
		}
	}
 
	if (flag == false) {
		cout << "IMPOSSIBLE";
	} else {
		for (int i = 1; i <= n; i++) {
			cout << visited[i] << " ";
		}
	}
 
	return 0;
 
}
