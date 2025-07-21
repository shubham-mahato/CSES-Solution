#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void bfs(vector<vector<int>> &adj)
{
  int n = adj.size();
  vector<int> ans;
  vector<int> vis(n, -1);
  queue<int> q;
  q.push(0);
  vis[0] = 1;

  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    for (int x : adj[node])
    {
      if (!vis[x])
      {
        vis[x] = 1;
        q.push(x);
      }
    }
  }
}

void dfs(int n, vector<vector<int>> &adj, vector<bool> &vis)
{
  vis[n] = true;
  for (int x : adj[n])
  {
    if (!vis[x])
    {
      dfs(x, adj, vis);
    }
  }
}

void dijkstra_algo(int start, vector<vector<pair<int, int>>> &adj, vector<int> &dist)
{
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  dist[start] = 0;
  pq.push({0, start});
  while (!pq.empty())
  {
    auto [weight, node] = pq.top();
    pq.pop();

    if (weight > dist[node])
      continue;

    for (auto [x, w] : adj[node])
    {
      if (dist[node] + w < dist[x])
      {
        dist[x] = dist[node] + w;
        pq.push({dist[x], x});
      }
    }
  }
}

void Bellman_Ford(int V, int start, vector<vector<int>> &edges, vector<int> &dist)
{
  dist[start] = 0;
  for (int i = 0; i < V - 1; i++)
  {
    for (auto &edge : edges)
    {
      int u = edge[0], v = edge[1], wt = edge[2];
      if (dist[u] != INT_MAX and dist[u] + wt < dist[v])
      {
        dist[v] = dist[u] + wt;
      }
    }
  }
}

