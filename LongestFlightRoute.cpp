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
	vector<int> indegree(n + 1, 0);
	unordered_map<int, vector<int>> graph;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
		indegree[v]++;
	}
 
	vector<int> v;
	queue<int> q;
	vector<int> visited(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			visited[i] = 1;
		}
	}
 
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		v.push_back(node);
		for (int nbr : graph[node]) {
			if (!visited[nbr]) {
				indegree[nbr]--;
				if (indegree[nbr] == 0) {
					q.push(nbr);
					visited[nbr] = 1;
				}
			}
		}
	}
 
	vector<int> distance(n + 1, -1e15);
	vector<int> parent(n + 1, -1);
	distance[1] = 0;
	int i;
	for (i = 0; i < (int) v.size(); i++) {
		if (v[i] == 1) {
			break;
		}
	}
 
	for (; i < (int) v.size(); i++) {
		for (int nbr : graph[v[i]]) {
			if (distance[v[i]] + 1 > distance[nbr]) {
				parent[nbr] = v[i];
				distance[nbr] = distance[v[i]] + 1;
			}
		}
	}
 
	vector<int> ans;
	if (distance[n] == -1e15) {
		cout << "IMPOSSIBLE";
	} else {
		int node = n;
		while (parent[node] != -1 && node != 1) {
			ans.push_back(node);
			node = parent[node];
		}
		if (node != 1) {
			cout << "IMPOSSIBLE";
			return 0;
		}
		ans.push_back(node);
		cout << ans.size() << endl;
		for (int i = (int) ans.size() - 1; i >= 0; i--) {
			cout << ans[i] << " ";
		}
	}
 
	return 0;
 
}
