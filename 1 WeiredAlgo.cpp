#include <iostream>
using namespace std;

#define int long long

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int num;
  cin >> num;

  cout << num;
  while (num != 1)
  {
    if (num % 2 == 0)
      num /= 2;
    else
      num = num * 3 + 1;
    cout << " " << num;
  }

  return 0;
}
