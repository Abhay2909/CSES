#include <bits/stdc++.h>
using namespace std;
 
#define int long long int
 
int32_t main(){
 
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
 
	int n, m; cin >> n >> m;
	unordered_map<int, vector<int>> graph;
	vector<int> indegree(n + 1, 0);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
		indegree[v]++;
	}
 
	vector<int> visited(n + 1, 0);
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			visited[i] = 1;
		}
	}
 
	vector<int> v;
 
	while (!q.empty()) {
		int node = q.front();
		// cout << node << " ";
		v.push_back(node);
		q.pop();
		for (int nbr : graph[node]) {
			if (visited[nbr] == 1) {
				continue;
			}
			indegree[nbr]--;
			if (indegree[nbr] == 0) {
				q.push(nbr);
				visited[nbr] = 1;
			}
		}
	}
 
	if ((int) v.size() != n) {
		cout << "IMPOSSIBLE";
	} else {
		for (int i = 0; i < (int) v.size(); i++) {
			cout << v[i] << " ";
		}
	}
 
	return 0;
 
}
