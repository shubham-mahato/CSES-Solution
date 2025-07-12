#include <bits/stdc++.h>
using namespace std;

void bfs(int n, vector<vector<int>> &adj, vector<int> &vis, vector<int> &path, int &count, vector<pair<int, int>> &newRoads)
{
  for (int i = 1; i <= n; i++)
  {
    if (vis[i] == -1)
    {
      vis[i] = i;
      count++;
      if (i != 1)
      {
        newRoads.push_back({vis[i - 1], i});
      }
      queue<int> q;
      q.push(i);
      while (!q.empty())
      {
        int node = q.front();
        q.pop();
        path.push_back(node);

        for (int neighbour : adj[node])
        {
          if (vis[neighbour] == -1)
          {
            q.push(neighbour);
            vis[neighbour] = i;
          }
        }
      }
    }
  }
}

int main()
{
  int m, n;
  cin >> n;
  cin >> m;

  vector<pair<int, int>> roads(m);

  for (int i = 0; i < m; i++)
  {
    cin >> roads[i].first >> roads[i].second;
  }
  // Creating Adj List

  vector<vector<int>> adj(n + 1);

  for (auto road : roads)
  {
    adj[road.first].push_back(road.second);
    adj[road.second].push_back(road.first);
  }
  vector<int> vis(n + 1, -1);
  vector<int> path;
  vector<pair<int, int>> newRoads;
  int count = 0;
  bfs(n, adj, vis, path, count, newRoads);

  cout << count - 1 << endl;
  for (auto road : newRoads)
  {
    cout << road.first << " " << road.second << endl;
  }

  return 0;
}