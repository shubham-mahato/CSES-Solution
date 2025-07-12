#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < m; i++)
  {
    int from, to;
    cin >> from >> to;
    adj[from].push_back(to);
    adj[to].push_back(from);
  }
  vector<bool> vis(n + 1, false);
  vector<int> parent(n + 1, -1);
  queue<int> q;
  q.push(1);
  vis[1] = true;

  while (!q.empty())
  {
    int node = q.front();
    q.pop();

    for (int nei : adj[node])
    {
      if (!vis[nei])
      {
        vis[nei] = true;
        parent[nei] = node;
        q.push(nei);
      }
    }
  }
  if (!vis[n])
  {
    cout << "IMPOSSIBLE";
    return 0;
  }
  vector<int> path;
  for (int i = n; i != -1; i = parent[i])
  {
    path.push_back(i);
  }
  reverse(path.begin(), path.end());
  cout << path.size() << endl;
  for (int x : path)
  {
    cout << x << " ";
  }
  return 0;
}