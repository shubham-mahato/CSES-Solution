#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int t;
  cin >> t;
  vector<long long> arr;
  while (t--)
  {
    long long y, x, val;
    cin >> y >> x;
    long long n = max(y, x);
    if (n % 2 == 0)
    {
      if (n == y)
      {
        val = n * n - x + 1;
      }
      else
      {
        val = (n - 1) * (n - 1) + y;
      }
    }
    else
    {
      if (n == y)
      {
        val = (n - 1) * (n - 1) + x;
      }
      else
      {
        val = n * n - y + 1;
      }
    }
    arr.push_back(val);
  }

  for (long long a : arr)
  {
    cout << a << endl;
  }

  return 0;
}