#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int x,n;
    while(t--){
        cin>>x>>n;
        if(n%2==0) cout<<0<<endl;
        else if(n%2==1) cout<<x<<endl;
    }
}