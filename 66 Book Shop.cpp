#include<iostream>
#include<vector>

using namespace std;

int calculation(int n,vector<int>costs,vector<int>pages,int total){
  vector<vector<int>>dp(n+1,vector<int>(total+1,0));

  for(int i=1;i<=n;i++){
    for(int j=1;j<=total;j++){
      if(j>=costs[i-1]){
        dp[i][j] = max(dp[i-1][j],pages[i-1]+dp[i-1][j-costs[i-1]]);
      }else{
        dp[i][j] = dp[i-1][j];
      }
    }
  }
  return dp[n][total];
}

int main(){
  int n,total;
  cin>>n>>total;
  vector<int>costs(n);
  vector<int>pages(n);
  for(int i=0;i<n;i++){
    cin>>costs[i];
  }
  for(int i=0;i<n;i++){
    cin>>pages[i];
  }
  int ans = calculation(n,costs,pages,total);
  cout<<ans;
  return 0;
}