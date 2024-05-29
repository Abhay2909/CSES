#include <bits/stdc++.h>
using namespace std;
 
#define int 				long long int
#define endl 				'\n'
 
void dfs(int node, int parent, vector<int> &reachable, vector<int> &visited, vector<vector<int>> &graph) {
	if (visited[node] == 1) {
		return;
	}
 
	visited[node] = 1;
	reachable.push_back(node);
	for (auto nbr: graph[node]) {
		if (nbr == parent) {
			continue;
		}
		dfs(nbr, node, reachable, visited, graph);
	}
}
 
int32_t main() {
 
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	int n, m; cin >> n >> m;
	vector<pair<pair<int, int>, int>> edges;
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		edges.push_back({{u, v}, -w});
	}
 
	vector<int> distance(n + 1, LLONG_MAX);
	distance[1] = 0;
 
	for (int i = 1; i <= n; i++) {
		for (auto &p : edges) {
			int u = p.first.first;
			int v = p.first.second;
			int w = p.second;
			if (distance[u] != LLONG_MAX) {
				distance[v] = min(distance[v], distance[u] + w);
			}
		}
	}
 
	set<int> temp;
	for (auto &p : edges) {
		int u = p.first.first;
		int v = p.first.second;
		int w = p.second;
		if (distance[u] != LLONG_MAX) {
			int x = distance[v];
			distance[v] = min(distance[v], distance[u] + w);
			if (x != distance[v]) {
				temp.insert(v);
			}
		}
	}
 
	for (auto &p : edges) {
		swap(p.first.first, p.first.second);
	}
 
	vector<vector<int>> rev(n + 1);
	for (int i = 0; i < m; i++) {
		int u = edges[i].first.first;
		int v = edges[i].first.second;
		rev[u].push_back(v);
	}
 
	vector<int> reachable;
	vector<int> visited(n + 1, 0);
	dfs(n, -1, reachable, visited, rev);
 
	bool f = true;
	for (auto i : reachable) {
		if (temp.find(i) != temp.end()) {
			f = false;
			break;
		}
	}
 
	if (f) {
		cout << -distance[n];
	} else {
		cout << -1;
	}
 
	return 0;
 
}
