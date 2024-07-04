#include <bits/stdc++.h>
using namespace std;
 
#define int 				long long int
#define endl 				'\n'
#define vi 					vector<int>
#define pi 					pair<int, int>
#define ff 					first
#define ss 					second
#define pb 					push_back
#define mp 					make_pair
#define rep(i, a, b) 		for (int i = a; i <= b; i++)
 
void dfs(int s, int e, unordered_map<int, vector<int>> &graph, unordered_map<int, int> &count) {
	count[s] = 1;
	for (int nbr : graph[s]) {
		if (nbr != e) {
			dfs(nbr, s, graph, count);
			count[s] += count[nbr];
		}
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
 
	int n; cin >> n;
	unordered_map<int, vector<int>> graph;
	for (int i = 2; i <= n; i++) {
		int u; cin >> u;
		graph[u].push_back(i);
		graph[i].push_back(u);
	}
 
	unordered_map<int, int> count;
	dfs(1, 0, graph, count);
 
	for (int i = 1; i <= n; i++) {
		cout << count[i] - 1 << " ";
	}
 
	return 0;
 
}
