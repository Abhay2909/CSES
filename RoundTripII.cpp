#include <bits/stdc++.h>
using namespace std;

#define int 				long long int
#define endl 				'\n'

int cycle_start, cycle_end;

bool dfs(int node, int par, vector<int> &visited, vector<int> &parent, vector<int> &st, unordered_map<int, vector<int>> &graph) {
	visited[node] = 1;
	parent[node] = par;
	st[node] = 1;
	for (int nbr : graph[node]) {
		if (!visited[nbr]) {
			bool cycle = dfs(nbr, node, visited, parent, st, graph);
			if (cycle) {
				return true;
			}
		} else if (st[nbr] == 1) {
			cycle_start = nbr;
			cycle_end = node;
			return true;
		}
	}

	st[node] = 0;

	return false;
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
	unordered_map<int, vector<int>> graph;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		if (u != v) {
			graph[u].push_back(v);
		}
	}

	vector<int> visited(n + 1, 0);
	vector<int> parent(n + 1, -1);
	vector<int> st(n + 1, 0);

	bool flag = false;

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			if (dfs(i, -1, visited, parent, st, graph)) {
				flag = true;
				break;
			}
		}
	}

	if (!flag) {
		cout << "IMPOSSIBLE";
	} else {
		vector<int> v;
		v.push_back(cycle_start);
		int node = cycle_end;
		while (node != cycle_start) {
			v.push_back(node);
			node = parent[node];
		}
		v.push_back(cycle_start);
		cout << v.size() << endl;
		for (int i = (int) v.size() - 1; i >= 0; i--) {
			cout << v[i] << " ";
		}
	}

	return 0;

}
