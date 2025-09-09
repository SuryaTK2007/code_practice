#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int x;
    while(t--){
        cin>>x;
        string str1=to_string(x);
        for(int i=1; i<INT_MAX; i++){
            string str2=to_string(i);
            string res=str1+str2;
            int y=stoi(res);
            int sum=x+i;
            if(y%sum==0){
                cout<<i<<endl;
                break;
            }
        }
    }
}