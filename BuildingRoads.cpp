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
 
	int count = 0;
	vector<int> v;
	vector<int> visited(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) {
			count++;
			v.push_back(i);
			visited[i] = 1;
			queue<int> q;
			q.push(i);
			while (!q.empty()) {
				int node = q.front();
				q.pop();
				for (int nbr : graph[node]) {
					if (!visited[nbr]) {
						q.push(nbr);
						visited[nbr] = 1;
					}
				}
			}
		}
	}
 
	cout << v.size() - 1 << endl;
	if (v.size() > 1) {
		for (int i = 1; i < (int) v.size(); i++) {
			cout << v[0] << " " << v[i] << endl;
		}
	}
 
	return 0;
 
}
