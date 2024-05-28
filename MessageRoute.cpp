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
 
	vector<int> visited(n + 1, 0);
	vector<int> parent(n + 1, 0);
	queue<pair<int, int>> q;
	q.push({1, 1});
	visited[1] = 1;
	parent[1] = -1;
	while (!q.empty()) {
		auto node = q.front();
		if (node.first == n) {
			break;
		}
		q.pop();
		for (int nbr : graph[node.first]) {
			if (!visited[nbr]) {
				visited[nbr] = 1;
				parent[nbr] = node.first;
				q.push({nbr, node.second + 1});
			}
		}
	}
 
	if (visited[n]) {
		int count = 0;
		vector<int> v;
		int node = n;
		while (node != -1) {
			count++;
			v.push_back(node);
			node = parent[node];
		}
 
		cout << count << endl;
		for (int i = (int) v.size() - 1; i >= 0; i--) {
			cout << v[i] << " ";
		}
	} else {
		cout << "IMPOSSIBLE";
	}
 
	return 0;
 
}
