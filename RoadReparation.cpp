#include <bits/stdc++.h>
using namespace std;
 
#define int long long int
 
int32_t main(){
 
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
 
	int n, m; cin >> n >> m;
	unordered_map<int, vector<pair<int, int>>> graph;
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
	}
 
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, 1});
	vector<int> visited(n + 1, 0);
 
	int ans = 0;
 
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
 
		int node = p.second;
		int d = p.first;
 
		if (visited[node] == 1) {
			continue;
		}
		visited[node] = 1;
		ans += d;
 
		for (auto nbr : graph[node]) {
			if (visited[nbr.first] == 1) {
				continue;
			}
 
			pq.push({nbr.second, nbr.first});
		}
	}
 
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) {
			cout << "IMPOSSIBLE";
			return 0;
		}
	}
 
	cout << ans;
 
	return 0;
 
}
