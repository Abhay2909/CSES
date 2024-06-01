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
 
void dfs(int node, vector<int> graph[], bool *visited, vector<int> &st) {
	visited[node] = true;
	for (int nbr : graph[node]) {
		if (!visited[nbr]) {
			dfs(nbr, graph, visited, st);
		}
	}
 
	st.push_back(node);
}
 
void dfs2(int node, vector<int> reverse_graph[], bool *visited) {
	visited[node] = true;
	for (int nbr : reverse_graph[node]) {
		if (!visited[nbr]) {
			dfs2(nbr, reverse_graph, visited);
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
 
	vector<int> st;
	bool visited[n + 1];
	memset(visited, 0, n + 1);
 
	rep(i, 1, n) {
		if (!visited[i]) {
			dfs(i, graph, visited, st);
		}
	}
 
	memset(visited, 0, n + 1);
	int component = 0;
	int a, b;
	for (int x = st.size() - 1; x >= 0; x--) {
		int node = st[x];
		if (!visited[node]) {
			component++;
			if (component == 1) {
				a = node;
			} else if (component == 2) {
				b = node;
			}
 
			dfs2(node, reverse_graph, visited);
		}
	}
 
	if (component >= 2) {
		cout << "NO" << endl << b << " " << a;
	} else {
		cout << "YES";
	}
 
	return 0;
 
}
