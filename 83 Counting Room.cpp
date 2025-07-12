#include <bits/stdc++.h>
using namespace std;


int main()
{
  int n, m;
  cin >> n;
  cin >> m;
  vector<vector<char>> room(n, vector<char>(m));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> room[i][j];
    }
  }

  int count=0;
  queue<pair<int,int>>q;
  vector<vector<bool>> vis(n,vector<bool>(m,false));
  vector<pair<int,int>> dir ={{1,0},{-1,0},{0,1},{0,-1}};
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(room[i][j]=='.' and !vis[i][j]){
        count++;
        q.push({i,j});
        vis[i][j] =true;
        while(!q.empty()){
          int x = q.front().first;
          int y= q.front().second;
          q.pop();

          for(auto d: dir){
            int dx = x+ d.first;
            int dy = y+ d.second;

            if(dx>=0 and dy>=0 and dx<n and dy<m and !vis[dx][dy] and room[dx][dy]=='.' ){
              vis[dx][dy]=true;
              q.push({dx,dy});
            }
          }
        }
      }
    }
  }
  cout<<count;
  return 0;
}