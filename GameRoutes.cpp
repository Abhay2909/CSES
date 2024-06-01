#include <bits/stdc++.h>
using namespace std;
 
#define int 				long long int
#define endl 				'\n'
 
const int modulo = 1e9 + 7;
 
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
	vector<int> indegree(n + 1, 0);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
		indegree[v]++;
	}
 
	vector<int> v;
	queue<int> q;
	vector<int> visited(n + 1, 0);
	for (int i = 1; i < n; i++) {
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
					visited[nbr] = 1;
					q.push(nbr);
				}
			}
		}
	}
 
	int i = 0;
	while (i < (int) v.size()) {
		if (v[i] == 1) {
			break;
		}
	}
 
	vector<int> count(n + 1, 0);
	count[1] = 1;
 
	while (i < (int) v.size()) {
		for (int nbr : graph[v[i]]) {
			count[nbr] = (count[nbr] % modulo + count[v[i]] % modulo) % modulo;
		}
		i++;
	}
 
	cout << count[n];
 
	return 0;
 
}
