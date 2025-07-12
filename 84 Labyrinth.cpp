#include <bits/stdc++.h>
using namespace std;

bool bfs(int n, int m, vector<vector<char>> &room, pair<int, int> start, pair<int, int> stop,int &lengthOfPath , string & path)
{
  vector<vector<bool>> vis(n, vector<bool>(m, false));
  vector<vector<pair<pair<int,int>,char>>> parent (n,vector<pair<pair<int,int>,char>>(m,{{-1,-1},'#'}));
  queue<pair<int,int>> q;
  q.push(start);
  vis[start.first][start.second] = true;

  int dir_x[] ={0,-0,-1,1};
  int dir_y[] ={1,-1,0,0};
  char dir_p[] ={'R','L','U','D'}; 
  while(!q.empty()){
    int x= q.front().first;
    int y= q.front().second;
    q.pop();
    vis[x][y] = true;

    if(x==stop.first and y==stop.second){
      string revPath="";
      while(make_pair(x,y)!= start){
        auto [prev,move] =parent[x][y];
        revPath+=move;
        x = prev.first;
        y= prev.second; 
      }
      reverse(revPath.begin(),revPath.end());
      path =revPath;
      lengthOfPath =path.size();
      return true;
    }

    for(int i=0;i<4;i++){
      int dx= x+dir_x[i];
      int dy= y+dir_y[i];
      if(dx>=0 and dy>=0 and dx<n and dy<m and !vis[dx][dy] and room[dx][dy]!='#'){
        vis[dx][dy] =true;
        parent[dx][dy] ={{x,y},dir_p[i]};
        q.push({dx,dy});
      }
    }
  }
  return false;
}

int main()
{
  int n, m;
  cin >> n;
  cin >> m;

  vector<vector<char>> room(n, vector<char>(m));
  pair<int, int> start, stop;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> room[i][j];
      if (room[i][j] == 'A')
      {
        start = {i, j};
      }
      if (room[i][j] == 'B')
      {
        stop = { i, j };
      }
    }
  }
  int lengthOfPath =0;
  string path="";

  string ans = bfs(n, m, room, start, stop,lengthOfPath,path) ? "YES" : "NO";
  if(ans=="YES")
  cout << ans<<"\n"<<lengthOfPath<<"\n"<<path;
  else
  cout<<ans;
  return 0;
}