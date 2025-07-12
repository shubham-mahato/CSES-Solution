#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const long long INF = 1e18;

void dijkstra (vector<vector<pair<int,int>>>& adj, vector<long long>&dist){

  priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
  dist[1]=0;
  pq.push({0,1});

  while(!pq.empty()){
    auto[ dis, node] =pq.top();
    pq.pop();
    if(dis>dist[node]) continue;

    for(auto [nei , weight]:adj[node]){
      if(dist[node] + weight <dist[nei]){
        dist[nei]= dis + weight;
        pq.push({dist[nei],nei});
      }
    }
  }
}
int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n + 1);
  for (int i = 0; i < m; i++)
  {
    int from, to, weight;
    cin >> from >> to >> weight;
    adj[from].push_back({to, weight});// one way flight (DAG) with  no negative weights
  }
  vector<long long> dist(n + 1, INF);
  dijkstra(adj,dist);

  for (int i = 1; i <= n; i++)
  {
    cout << dist[i] << " ";
  }
  return 0;
}