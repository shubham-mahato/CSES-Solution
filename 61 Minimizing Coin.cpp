#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int minCoin(int n, vector<int> coins, int x)
{
  int inf = INT_MAX - 1;
  vector<vector<int>> dp(n + 1, vector<int>(x + 1, inf));
  for(int i=0;i<=n;i++){
    dp[i][0]=0;
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= x; j++)
    {
      if ((j >= coins[i - 1]))
      {
        dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
      }
      else
      {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  return dp[n][x]==(inf)?-1:dp[n][x];
}

int main()
{
  int n, x;
  cin >> n >> x;
  vector<int> coins(n);
  for (int i = 0; i < n; i++)
  {
    cin >> coins[i];
  }
  int ans = minCoin(n, coins, x);
  cout << ans;
  return 0;
}