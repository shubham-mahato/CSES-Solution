#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < m; i++)
  {
    int f1, f2;
    cin >> f1 >> f2;
    adj[f1].push_back(f2);
    adj[f2].push_back(f1);
  }

  vector<bool> vis(n + 1, false);
  vector<int> color(n + 1, 0);

  for (int i = 1; i <= n; i++)
  {
    if (!vis[i])
    {
      queue<int> q;
      q.push(i);
      vis[i] = true;
      int c = 1;
      color[i]=c;
      while (!q.empty())
      {
        int node = q.front();
        q.pop();
        
        for (int nei : adj[node])
        {
          if (!vis[nei])
          {
            vis[nei] = true;
            color[nei]=(-1)*color[node];
            q.push(nei);
          }
          else if(color[nei]==color[node]){
            cout<<"IMPOSSIBLE";
            return 0;
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; i++)
  {
    if(color[i]==-1){
      color[i]=2;
    }
    cout << color[i] << " ";
  }
  return 0;
}