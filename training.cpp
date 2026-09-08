#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin>>n;
    bool flag=false;
    for(int i=2; i*i<=n; i++){
        if(n%i==0){
            flag=true;
            break;
        }
    }
    if(!flag) cout<<"Prime"<<endl;
    else cout<<"Not prime"<<endl;
}