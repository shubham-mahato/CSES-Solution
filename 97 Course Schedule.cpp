#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> courses(n + 1);
  vector<int> indegree(n + 1, 0);
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    courses[a].push_back(b);
    indegree[b]++;
  }
  queue<int> q;
  for (int i = 1; i <= n; i++)
  {
    if (indegree[i] == 0)
    {
      q.push(i);
    }
  }
  vector<int> ans;
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    ans.push_back(node);
    for(int it:courses[node]){
      indegree[it]--;
      if(indegree[it]==0){
        q.push(it);
      }
    }
  }
  for(int i=1;i<=n;i++){
    if(indegree[i]!=0){
      cout<<"IMPOSSIBLE";
      return 0;
    }
  }
  for(int x:ans){
    cout<<x<<" ";
  }
  return 0;
}