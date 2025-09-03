#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,x;
	cin>>n;
	vector<int>temp;
	while(n--){
		cin>>x;
		temp.push_back(x);
	}
	for(int i: temp){
		if(i%2) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
}