#include <bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n; cin>>n;
	while(n!=1){
		cout<<n<<" ";
		if(n%2==1){
			n=n*3+1;
		}
		else{
			n=n/2;
		}
	}
	cout<<1;

	return 0;

}
