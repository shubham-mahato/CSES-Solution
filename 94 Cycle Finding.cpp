#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bellman_ford(int n, vector<vector<int>> &edges, vector<long long> &dist, vector<int> &parent)
{
  int lastUpdated = -1;

  for (int i = 0; i < n; i++)
  {
    lastUpdated = -1;
    for (auto edge : edges)
    {
      int u = edge[0], v = edge[1], weight = edge[2];
      if (dist[u] + (long long)weight < dist[v])
      {
        dist[v] = dist[u] + (long long)weight;
        parent[v] = u;
        lastUpdated = v;
      }
    }
  }
  if (lastUpdated == -1)
  {
    cout << "NO\n";
  }
  else
  {
    cout << "YES\n";
    for (int i = 0; i < n; i++)
    {
      lastUpdated = parent[lastUpdated];
    }
    vector<int> cycle;
    int start = lastUpdated;
    cycle.push_back(start);
    int curr = parent[start];
    while (curr != start)
    {
      cycle.push_back(curr);
      curr = parent[curr];
    }
    cycle.push_back(start);
    reverse(cycle.begin(), cycle.end());
    for (int x : cycle)
    {
      cout << x<< " ";
    }
  }
}
int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> edges;
  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    edges.push_back({a, b, c});
  }
  vector<long long> dist(n + 1, 0);
  vector<int> parent(n + 1, -1);
  bellman_ford(n, edges, dist, parent);
  return 0;
}