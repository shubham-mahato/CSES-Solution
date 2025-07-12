#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  long long moves = 0;
  int prev;
  cin >> prev;

  for (int i = 1; i < n; i++)
  {
    int curr;
    cin >> curr;

    if (curr < prev)
    {
      moves += (prev - curr);
    }
    else
    {
      prev = curr;
    }
  }

  cout << moves;
  return 0;
}
