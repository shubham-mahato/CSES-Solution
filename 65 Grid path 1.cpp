#include <iostream>
#include <vector>
const int mod = 1000000007;
using namespace std;
int path(int n, vector<vector<char>> grid)
{
  vector<vector<int>> dp(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++)
  {
    if (grid[i][0] != '*')
      dp[i][0] = 1;
    else
      break;
  }
  for (int i = 0; i < n; i++)
  {
    if (grid[0][i] != '*')
      dp[0][i] = 1;
    else
      break;
  }
  for (int i = 1; i < n; i++)
  {
    for (int j = 1; j < n; j++)
    {
      if (grid[i][j] != '*')
      {
        dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
      }
      else
      {
        dp[i][j] = 0;
      }
    }
  }
  return dp[n - 1][n - 1];
}
int main()
{
  int n;
  cin >> n;
  vector<vector<char>> grid(n, vector<char>(n));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> grid[i][j];
    }
  }
  int ans = grid[n - 1][n - 1] == '*' ? 0 : path(n, grid);
  cout << ans;

  return 0;
}
