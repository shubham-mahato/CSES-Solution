#include <iostream>
#include <vector>
#include <climits>
using namespace std;
const long long INF = 1e18;
void floydWarshal(int n, vector<vector<long long>> &mat)
{

  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (mat[i][k] != INF and mat[k][j] != INF and mat[i][j] > mat[i][k] + mat[k][j])
        {
          mat[i][j] = mat[i][k] + mat[k][j];
        }
      }
    }
  }
}
int main()
{
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<long long>> mat(n + 1, vector<long long>(n + 1, INF));
  for (int i = 0; i < m; i++)
  {
    int from, to;
    long long weight;
    cin >> from >> to >> weight;
    mat[from][to] = min(mat[from][to],weight);
    mat[to][from] = min(mat[to][from], weight);
  }
  for (int i = 1; i <= n; i++)
  {
    mat[i][i] = 0;
  }
  vector<pair<int, int>> queries;
  while (q--)
  {
    int from, to;
    cin >> from >> to;
    queries.push_back({from, to});
  }
  floydWarshal(n, mat);

  for (auto q : queries)
  {
    int from = q.first;
    int to = q.second;
    if (mat[from][to] == INF)
    {
      cout << "-1" << endl;
    }
    else
    {
      cout << mat[from][to] << endl;
    }
  }
  return 0;
}