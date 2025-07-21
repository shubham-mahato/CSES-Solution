#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix_array(string pattern, int m)
{
  vector<int> pi(m);
  pi[0] = 0;
  int j = 0;
  for (int i = 1; i < m; i++)
  {
    j = pi[i - 1];
    while (j > 0 and pattern[i] != pattern[j])
    {
      j = pi[j - 1];
    }
    if (pattern[i] == pattern[j])
    {
      j++;
    }
    pi[i] = j;
  }
  return pi;
}
vector<int> kmp(string text, string pattern)
{
  int n = text.size(), m = pattern.size();
  vector<int> pi = prefix_array(pattern, m);
  vector<int> result;
  int j = 0;

  for (int i = 0; i < n; i++)
  {
    while (j > 0 and text[i] != pattern[j])
    {
      j = pi[j - 1];
    }
    if (text[i] == pattern[j])
    {
      j++;
    }
    if (j == m)
    {
      result.push_back(i - m + 1);
      j = pi[j - 1];
    }
  }
  return result;
}
int main()
{
  string text, pattern;
  cin >> text >> pattern;
  vector<int> result = kmp(text, pattern);
  cout<<result.size();
  return 0;
}