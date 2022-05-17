#include<bits/stdc++.h>
using namespace std;
#define int long long 

int main()
{
    int tt, tc;
    cin>>tt;
    for(int tc = 0; tc< tt; tc++)
    {
        int n, m , p, s, t, i, j, k;
        cin >>n;
        vector<pair<int, int>>graph[n];
        map<string, int>city;
        string str;
        for(i = 0; i<n; i++)
        {
            cin >> str;
            city.insert({str, i});
            cin>>m;
            for(j = 0; j<m; j++)
            {
                int v, d;
                cin>>v>>d;
                v--;
                graph[i].push_back({v, d});
            }
        }
        cin>>p;
        while(p--)
        {
            cin>>str;
            s = city[str];
            cin>>str;
            t = city[str];
            int dist[n];
            fill(dist, dist+n, INT_MAX);
            dist[s] = 0;
            bool visited[n];
            fill(visited, visited+n, 0);
            priority_queue<pair<int, int>>q;
            q.push({-dist[s], s});
            while(!q.empty())
            {
                pair<int, int>p = q.top();
                int x = -p.first,y = p.second;
                q.pop();
                
                visited[y] = 1;
                if(y == t) break;
                for(j = 0;j<graph[y].size();j++)
                {
                    int k = graph[y][j].first;
                    if(visited[k]) continue;
                    int cost = x+graph[y][j].second;
                    if(cost<dist[k])
                    {
                        dist[k] = cost;
                        q.push({-cost, k});
                    }
                }
            }
            cout<<dist[t]<<endl;
        }
    }
}