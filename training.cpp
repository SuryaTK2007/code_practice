#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> indegree(n+1,0);
    vector<int> outdegree(n+1,0);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        outdegree[u]++;
        indegree[v]++;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<"Node "<<i<<": Indegree = "<<indegree[i]<<", Outdegree = "<<outdegree[i]<<endl;
    }
    return 0;
}