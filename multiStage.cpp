#include<bits/stdc++.h>
using namespace std;
#define N 5
#define INF INT_MAX
int shortestDist(int graph[N][N]) {
    int dist[N];
    dist[N-1] = 0;
    for(int i=N-2; i>=0; i--){
        dist[i]=INF;
        for(int j=i+1; j<N; j++){
            if(graph[i][j]==INF) continue;
            dist[i]=min(dist[i], graph[i][j]+dist[j]);
        }
    }
    return dist[0];
}
int main()
{
    int graph[N][N] =
      {{0, 4, INF, 5, INF},
        {INF, 0, 1, INF, 6},
        {2, INF, 0, 3, INF},
        {INF, INF, 1, 0, 2},
        {1, INF, INF, 4, 0}};
    cout << shortestDist(graph);
    return 0;
}