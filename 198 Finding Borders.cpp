#include <iostream>
#include <vector>
using namespace std;

vector<int> z_algo(string s)
{
  int n = s.size();
  vector<int> z(n);
  int left = 0, right = 0;
  z[0] = 0;
  for (int k = 1; k < n; k++)
  {
    if (k > right)
    {
      left = right = k;
      while (k < n and s[right] == s[right - left])
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
        while (k < n and s[right] == s[right - left])
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
main()
{
  string s;
  cin >> s;
  int n = s.size();
  vector<int> z = z_algo(s);
  vector<int> ans;
  for (int i = n - 1; i >= 0; i--)
  {
    if ((i + z[i]) == n)
    {
      ans.push_back(z[i]);
    }
  }
  for (int a : ans)
  {
    cout << a << " ";
  }
}