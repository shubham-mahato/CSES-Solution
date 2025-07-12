#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  unordered_map<char, int> ump;
  for (char ch : s) ump[ch]++;

  int oddCount = 0;
  char single;
  for (auto u : ump) {
    if (u.second % 2 != 0) {
      oddCount++;
      single = u.first;
    }
  }
  if (oddCount > 1) {
    cout << "NO SOLUTION";
    return 0;
  }

  string half = "";
  for (auto u : ump) {
    int count = u.second / 2;
    for (int i = 0; i < count; i++) {
      half += u.first;
    }
  }

  string revHalf = half;
  reverse(revHalf.begin(), revHalf.end());

  if (oddCount == 1) {
    cout << half << string(ump[single], single).substr(ump[single]/2, 1) << revHalf;
  } else {
    cout << half << revHalf;
  }

  return 0;
}
