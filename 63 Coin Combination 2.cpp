#include<iostream>
#include<vector>
using namespace std;
const int mod =1000000007;

int combination(int n,vector<int>coins,int sum){
  vector<vector<int>> dp(n+1,vector<int>(sum+1,0));

  for(int i=0;i<=n;i++){
    dp[i][0]=1;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=sum;j++){
      if(j>=coins[i-1]){
        dp[i][j] = (dp[i-1][j] + dp[i][j-coins[i-1]])%mod;
      }else{
        dp[i][j] = dp[i-1][j];
      }
    }
  }
  return dp[n][sum];
}
int main(){
  int n,sum;
  cin>>n>>sum;
  vector<int> coins(n);
  for(int i=0;i<n;i++){
    cin>>coins[i];
  }
  int ans = combination(n,coins,sum);
  cout<<ans;
  return 0;
}