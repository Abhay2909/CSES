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
 
class DisjointSet {
	vi parent;
	vi size;
	multiset<int> st;
public:
	DisjointSet(int n) {
		parent.resize(n + 1);
		size.resize(n + 1, 1);
		rep(i, 1, n) {
			parent[i] = i;
		}
		st.insert(1);
	}
 
	int find(int node) {
		if (node == parent[node]) {
			return node;
		}
 
		return parent[node] = find(parent[node]);
	}
 
	void unite(int u, int v) {
		int parU = find(u);
		int parV = find(v);
		if (parU == parV) {
			return;
		}
 
		st.erase(size[parU]);
		st.erase(size[parV]);
 
		if (size[parU] < size[parV]) {
			size[parV] += size[parU];
			parent[parU] = parV;
			st.insert(size[parV]);
		} else {
			size[parU] += size[parV];
			parent[parV] = parU;
			st.insert(size[parU]);
		}
	}
 
	int maxSize() {
		return *(st.rbegin());
	}
};
 
int32_t main() {
 
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	int n, m; cin >> n >> m;
	DisjointSet ds(n);
	int components = n;
	rep(i, 1, m) {
		int u, v; cin >> u >> v;
		if (ds.find(u) != ds.find(v)) {
			components--;
		}
		ds.unite(u, v);
		cout << components << " " << ds.maxSize() << endl;
	}
 
	return 0;
 
}
