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
 
int component_no = 0;
 
void dfs(int node, bool *visited, vector<int> graph[], vector<int> &st) {
	visited[node] = true;
	for (auto nbr : graph[node]) {
		if (!visited[nbr]) {
			dfs(nbr, visited, graph, st);
		}
	}
 
	st.push_back(node);
}
 
void dfs2(int node, vector<int> reverse_graph[], bool *visited, vector<int> &component) {
	visited[node] = true;
	component[node] = component_no;
	for (auto nbr : reverse_graph[node]) {
		if (!visited[nbr]) {
			dfs2(nbr, reverse_graph, visited, component);
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
 
	int n, m; cin >> n >> m;
	vector<int> graph[n + 1];
	vector<int> reverse_graph[n + 1];
	rep(i, 1, m) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		reverse_graph[b].push_back(a);
	}
 
	bool visited[n + 1];
	memset(visited, 0, n + 1);
	vi st;
	rep(i, 1, n) {
		if (!visited[i]) {
			dfs(i, visited, graph, st);
		}
	}
 
	memset(visited, 0, n + 1);
	vi component(n + 1);
 
	for (int x = st.size() - 1; x >= 0; x--) {
		int node = st[x];
		if (!visited[node]) {
			component_no++;
			dfs2(node, reverse_graph, visited, component);
		}
	}
 
	cout << component_no << endl;
	rep(i, 1, n) {
		cout << component[i] << " ";
	}
 
	return 0;
 
}
