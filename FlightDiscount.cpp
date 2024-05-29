#include <bits/stdc++.h>
using namespace std;
 
#define int long long int
 
int32_t main(){
 
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
 
	int n, m; cin >> n >> m;
	map<pair<int, int>, int> edge;
	unordered_map<int, vector<pair<int, int>>> graph1;
	unordered_map<int, vector<pair<int, int>>> graph;
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		graph[u].push_back({v, w});
		graph1[v].push_back({u, w});
		edge[{u, v}] = w;
	}
 
	vector<int> distance(n + 1, LLONG_MAX);
	set<pair<int, int>> st;
	st.insert({0, 1});
	distance[1] = 0;
 
	while (!st.empty()) {
		auto it = *(st.begin());
		int node = it.second;
		int dist = it.first;
 
		st.erase(it);
 
		for (auto nbr : graph[node]) {
			if (distance[nbr.first] > nbr.second + dist) {
				if (distance[nbr.first] != LLONG_MAX) {
					st.erase({distance[nbr.first], nbr.first});
				}
				distance[nbr.first] = nbr.second + dist;
				st.insert({distance[nbr.first], nbr.first});
			}
		}
	}
 
	vector<int> distance1(n + 1, LLONG_MAX);
	set<pair<int, int>> st1;
	st1.insert({0, n});
	distance1[n] = 0;
 
	while (!st1.empty()) {
		auto it = *(st1.begin());
		int node = it.second;
		int dist = it.first;
 
		st1.erase(it);
 
		for (auto nbr : graph1[node]) {
			if (distance1[nbr.first] > dist + nbr.second) {
				if (distance1[nbr.first] != LLONG_MAX) {
					st1.erase({distance1[nbr.first], nbr.first});
				}
				distance1[nbr.first] = nbr.second + dist;
				st1.insert({distance1[nbr.first], nbr.first});
			}
		}
	}
 
	int ans = LLONG_MAX;
	for (auto &p : edge) {
		int u = p.first.first;
		int v = p.first.second;
		int w = p.second;
		if (distance[u] ==LLONG_MAX || distance1[v] == LLONG_MAX) {
			continue;
		}
		ans = min(ans, distance[u] + distance1[v] + (w / 2));
	}
 
	cout << ans;
 
	return 0;
 
}
