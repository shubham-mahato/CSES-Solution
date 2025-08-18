#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void lcs(int n, int m, vector<int> s1, vector<int> s2)
{
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (s1[i - 1] == s2[j - 1])
      {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  cout << dp[n][m] << endl;
  vector<int> ans;
  int i = n, j = m;
  while (i > 0 and j > 0)
  {
    if (s1[i - 1] == s2[j - 1])
    {
      ans.push_back(s1[i - 1]);
      i--;
      j--;
    }
    else if (dp[i - 1][j] > dp[i][j - 1])
      i--;
    else
      j--;
  }
  int size = ans.size();
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < size; i++)
  {
    cout << ans[i] << " ";
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<int> s1(n), s2(m);
  for (int i = 0; i < n; i++)
  {
    cin >> s1[i];
  }
  for (int i = 0; i < m; i++)
  {
    cin >> s2[i];
  }
  lcs(n, m, s1, s2);

  return 0;
}