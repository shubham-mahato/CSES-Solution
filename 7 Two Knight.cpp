#include <iostream>
using namespace std;
#define ll long long
int main()
{
  int n;
  cin >> n;
  for(ll k=1;k<=n;k++){
    ll total = (k*k)*(k*k -1)/2;
    ll attack = 4*(k-1)*(k-2);
    cout<<total-attack<<endl;
  }

  return 0;
}