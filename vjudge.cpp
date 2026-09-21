#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int upper=0;
    for(char c:s)
        if(isupper(c))
            upper++;
    int lower=0;
    int ans=upper;
    for(char c:s){
        if(isupper(c))
            upper--;
        else
            lower++;
        ans=min(ans,lower+upper);
    }
    cout<<ans<<endl;
}