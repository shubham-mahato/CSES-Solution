#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string dna;
  cin >> dna;
  int globalMax = 0, count = 0;
  char currCh = dna[0];
  for (char ch : dna)
  {
    if (currCh == ch)
    {
      count++;
    }
    else
    {
      currCh = ch;
      count = 1;
    }
    globalMax = max(globalMax, count);
  }
  cout << globalMax;
  return 0;
}