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
	unordered_map<int, vector<pair<int, int>>> graph;
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		graph[u].push_back({v, w});
	}
 
	vector<int> distance(n + 1, LLONG_MAX);
	vector<int> count(n + 1, 0);
	vector<int> mini(n + 1, 0);
	vector<int> maxi(n + 1, 0);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
 
	distance[1] = 0;
	count[1] = 1;
	mini[1] = 1;
	maxi[1] = 1;
	pq.push({0, 1});
 
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		int node = p.second;
		int d = p.first;
		if (distance[node] < d) {
			continue;
		}
		for (auto &nbr : graph[node]) {
			if (d + nbr.second < distance[nbr.first]) {
				distance[nbr.first] = d + nbr.second;
				count[nbr.first] = count[node];
				mini[nbr.first] = mini[node] + 1;
				maxi[nbr.first] = maxi[node] + 1;
				pq.push({distance[nbr.first], nbr.first});
			} else if (distance[nbr.first] == (d + nbr.second)) {
				count[nbr.first] = (count[nbr.first] % modulo + count[node] % modulo) % modulo;
				mini[nbr.first] = min(mini[nbr.first], mini[node] + 1);
				maxi[nbr.first] = max(maxi[nbr.first], maxi[node] + 1);
			}
		}
	}
 
	cout << distance[n] << " " << count[n] << " " << mini[n] - 1 << " " << maxi[n] - 1;
 
	return 0;
 
}
