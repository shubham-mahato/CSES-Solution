#include<iostream>
#include<vector>
using namespace std;
const int mod = 1000000007;
int permutation(vector<int>coins,int sum){
  vector<int>dp(sum+1,0);
  dp[0]=1;
  for(int i=1;i<=sum;i++){
    for(int coin:coins){
      if(i>=coin){
        dp[i] = (dp[i]+dp[i-coin])%mod;
      }
    }
  }
  return dp[sum];
}

int main(){
  int n,sum;
  cin>>n>>sum;
  vector<int>coins(n);
  for(int i=0;i<n;i++){
    cin>>coins[i];
  }
  int ans = permutation(coins,sum);
  cout<<ans;
  return 0;

}