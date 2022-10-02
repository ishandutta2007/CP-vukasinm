#include <bits/stdc++.h>
#define maxN  10000000
using namespace std;

int dist[maxN];
vector<pair<int,int>> adj[maxN];
bool visited[maxN];
int n,m;

void dijkstra(int v)
{
for(int i=1;i<=n;i++)
{
    if(i==v)
    {
        dist[i]=0;
    }
    else{
        dist[i]=-maxN;
    }
}
priority_queue<pair<int,int>> pq;
pq.push(make_pair(0,v));
while(!pq.empty())
{
    int k=pq.top().second;

    pq.pop();
    if(visited[k]==true) {continue;}
    else{
        visited[k]=true;
        for(int i=0;i<adj[k].size();i++)
        {
            if (dist[adj[k][i].second]<dist[k]+adj[k][i].first)
            {
                dist[adj[k][i].second]=dist[k]+adj[k][i].first;

                pq.push(make_pair(dist[adj[k][i].second],adj[k][i].second));
            }
        }

    }
}
}
int main()
{
    int x,y,w;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y>>w;
        adj[x].push_back(make_pair(-w,y));
        adj[y].push_back(make_pair(-w,x));
    }
    dijkstra(1);
    for(int j=2;j<=n;j++)
    {
        if(dist[j]==-maxN)
        {
            cout<<1000000000<<" ";
        }
        else{
        dist[j]=dist[j]*(-1);
        cout<<dist[j]<<" ";
        }
    }
    return 0;
}
