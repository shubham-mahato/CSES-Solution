#include <iostream>
#include <vector>
using namespace std;
vector<int> z_algorithm(string s)
{
  int n = s.size(), left = 0, right = 0;
  vector<int> z(n);
  z[0] = 0;

  for (int k = 1; k < n; k++)
  {
    if (k > right)
    {
      left = right = k;
      while (right < n and s[right] == s[right - left])
      {
        right++;
      }
      z[k] = right - left;
      right--;
    }
    else
    {
      int k1 = k - left;
      if (z[k1] < right - k + 1)
      {
        z[k] = z[k1];
      }
      else
      {
        left = k;
        while (right < n and s[right] == s[right - left])
        {
          right++;
        }
        z[k] = right - left;
        right--;
      }
    }
  }
  return z;
}
vector<int> kmp(string s)
{
  int n = s.size();
  vector<int> pi(n);
  pi[0] = 0;
  for (int k = 1; k < n; k++)
  {
    int j = pi[k - 1];
    while (j > 0 and s[j] != s[k])
    {
      j = pi[j - 1];
    }
    if (s[j] == s[k])
    {
      j++;
    }
    pi[k] = j;
  }
  return pi;
}
int main()
{
  string s;
  cin >> s;
  vector<int> result = z_algorithm(s);
  vector<int> ans = kmp(s);
  for (auto res : result)
  {
    cout << res << " ";
  }
  cout << endl;
  for (auto res : ans)
  {
    cout << res << " ";
  }
  return 0;
}