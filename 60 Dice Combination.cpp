#include <iostream>
#include <vector>
const int mod = 1000000007;
using namespace std;

int combination(int n)
{
  vector<int> dp(n + 1, 0);
  dp[0] = 1;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= 6; j++)
    {
      if (i - j >= 0)
      {
        dp[i] = (dp[i] + dp[i - j]) % mod;
      }
    }
  }
  return dp[n];
}
int main()
{
  int n;
  cin >> n;
  int ans = combination(n);
  cout << ans;
  return 0;
}