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
	unordered_map<int, vector<pair<int, int>>> graph;
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		graph[u].push_back({v, w});
	}
 
	set<pair<int, int>> s;
	vector<int> dist(n + 1, LLONG_MAX);
	dist[1] = 0;
	s.insert({0, 1});
	while (!s.empty()) {
		auto p = *(s.begin());
		int node = p.second;
		int d = p.first;
		s.erase(p);
 
		for (auto nbrs : graph[node]) {
			if (d + nbrs.second < dist[nbrs.first]) {
				auto f = s.find({dist[nbrs.first], nbrs.first});
				if (f != s.end()) {
					s.erase(f);
				}
				dist[nbrs.first] = d + nbrs.second;
				s.insert({dist[nbrs.first], nbrs.first});
			}
		}
	}
 
	for (int i = 1; i <= n; i++) {
		cout << dist[i] << " ";
	}
 
	return 0;
 
}
