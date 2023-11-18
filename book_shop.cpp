#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
 
int main(){
 
	int n, x; cin >> n >> x;
	vector<int> price;
	for (int i = 0; i < n; i++) {
		int no; cin >> no;
		price.push_back(no);
	}
	vector<int> pages;
	for (int i = 0; i < n; i++) {
		int no; cin >> no;
		pages.push_back(no);
	}

	vector<int> prev(x + 1, 0);

	for (int i = 1; i <= n; i++) {
		vector<int> curr(x + 1);
		for (int j = 0; j <= x; j++) {
			int p = price[i - 1];
			int page = pages[i - 1];
			int a = 0;
			if (j - p >= 0) {
				a = prev[j - p] + page;
			}
			int b = prev[j];
			curr[j] = max(a, b);
		}
		prev = curr;
	}

	cout << prev[x];
 
	return 0;
 
}
