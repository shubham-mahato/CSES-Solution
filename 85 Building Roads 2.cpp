#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<vector<int>>&adj,vector<bool>&vis,vector<int>&component){
  vis[node]=true;
  component.push_back(node);

    for(int neighbour: adj[node]){
      if(!vis[neighbour]){
        dfs(neighbour,adj,vis,component);
      }
    }
  
}
int main()
{
  int n,m;
  cin>>n>>m;
  vector<vector<int>> adj(n+1);
  for(int i=1;i<=m;i++){
    int from,to;
    cin>> from>> to;
    adj[from].push_back(to);
    adj[to].push_back(from);
  }

  vector<bool> vis(n+1,false);
  vector<int> representatives ;
  for(int i=1;i<=n;i++){

    if(!vis[i]){
      vector<int>component;
      dfs(i,adj,vis,component);
      representatives.push_back(i);
    }
  }
  cout<<representatives.size()-1<<endl;
  int a =representatives.size();
  for(int i=1;i<a;i++){
    cout<<representatives[i-1]<<" "<<representatives[i]<<endl;
  }
  return 0;
}