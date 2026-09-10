#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>adj[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        int indegree=0,outdegree=0;
        for(int j=1;j<=n;j++)
        {
            if(adj[i][j]==1)
            {
                outdegree++;
            }
            if(adj[j][i]==1)
            {
                indegree++;
            }
        }
        cout<<"Node "<<i<<": Indegree = "<<indegree<<", Outdegree = "<<outdegree<<endl;
    }
    return 0;
}