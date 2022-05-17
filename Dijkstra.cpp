// single source shortest path algorithm
// can be extended for multi-source (being considered simultaneously); but not all sources (separate) shortest path (use Floyd Warshall or Johnson instead)
// works only on non-negative edge weights
// both directed and undirected graphs
// Time complexity : O(E+V*logV)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF INT_MAX

/* struct _priority
{
    bool operator() (const pair <ll, ll> &a, const pair<ll, ll> &b) const
    {
        return a.second > b.
    }
}; */

vector<pair<ll, ll>>adj[1001];
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
vector<ll> dist;
vector<ll>parent;
void dijkstra(ll source)
{
    dist[source] = 0;
    
    pq.push({source, 0});

    while (!pq.empty())
    {
    
        int cur = pq.top().first;
        int cur_d = pq.top().second;
        pq.pop();

        for (int i=0;i<adj[cur].size();i++)
        {
            auto node = adj[cur][i];
            if (cur_d + node.second < dist[node.first])
            {
                dist[node.first] = cur_d + node.second;
                pq.push({node.first, dist[node.first]});
                parent[node.first] = cur;
            }
        }
    }
}
int main()
{
    ll nodes, edges, u, v, w;
    cin>>nodes>>edges;
    for(int i = 0;i<edges;i++)
    {
        cin>>u>>v>>w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dist.assign(nodes+1, INF);
    parent.assign(nodes+1, -1);
    ll source = 1;
    //cin>>source;
    dijkstra(source);
    
    
    
/*     for (ll i = 1; i <= nodes; i++)
    {
        if (dist[i] == INT_MAX)
        {
            cout << "inf";
        }
        else
        {
            cout << dist[i];
        }
        cout << " ";
    } */
    if (dist[nodes] >= INF)
    {
        cout << -1 << endl;
    }
    else
    {
        vector<int> ans;
        while (parent[nodes] != -1)
        {
            ans.push_back(nodes);
            nodes = parent[nodes];
        }
        ans.push_back(nodes);
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i] << " ";
        }
        return 0;
    }
}
