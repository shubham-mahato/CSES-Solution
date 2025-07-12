#include <iostream>
#include <vector>
using namespace std;
bool helper(vector<int>& arr, int i, int target, vector<vector<int>>&dp)
{
  if (target == 0)
  {
    return true;
  }
  if (i < 0 || target < 0)
  {
    return false;
  }
  if (dp[i][target] != -1)
  {
    return dp[i][target];
  }
  bool notPick = helper(arr, i - 1, target, dp);
  bool pick = false;
  if (target >= arr[i])
  {
    pick = helper(arr, i - 1, target - arr[i], dp);
  }
  dp[i][target] = pick || notPick;
  return dp[i][target];
}
int main()
{
  int n, sum = 0;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    sum += arr[i];
  }
  int target = sum / 2;
  vector<vector<int>> dp(n, (vector<int>(target+1, -1)));
 
   for (int i = target; i >= 0; i--) {
    if (helper(arr, n - 1, i, dp)) {
      cout << abs(sum - 2 * i) << endl;
      break;
    }
  }

  return 0;
}