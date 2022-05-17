
#include<iostream>
#include<vector>
#include<queue>

#define inf_max 2147483647
#define inf_min -2147483647
#define N 30010

using namespace std;
struct edge
{
    int to;
    int weight;
    edge () {}
    edge(int t, int w) : to(t), weight(w) {}
    bool operator<(const edge &e)const
    {
        return weight > e.weight;
    }
};
vector <edge> graph[50010];
priority_queue <edge> PQ;
edge e;
int dis[20010];
int dijkstra(int s, int end)
{
    int i, u, v, w;
    dis[s] = 0;
    PQ.push(edge(s, 0));
    while(!PQ.empty())
    {
        e = PQ.top();
        PQ.pop();
        u = e.to;
        for(i=0; i< (int)graph[u].size(); i++)
        {
            v = graph[u][i].to;
            w = graph[u][i].weight;
            if(dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                PQ.push(edge(v, dis[v]));
            }
        }
    }
    return dis[end];
}
int main()
{

    int tcase, i, t, n, m, start, end, a, b, w, res;
    cin >> tcase;
    for(t=1; t<=tcase; t++)
    {
        cin >> n >> m >> start >> end;

        for(i=0; i<n; i++)  dis[i] = inf_max;

        for(i=0; i<n; i++)  graph[i].clear();

        for(i=0; i<m; i++)
        {
            cin >> a >> b >> w;

            graph[a].push_back(edge(b, w));
            graph[b].push_back(edge(a, w));
        }
        res = dijkstra(start, end);

        if(res == inf_max)printf("Case #%d: unreachable\n", t);
        else printf("Case #%d: %d\n",t, res);
    }
    return 0;
}
