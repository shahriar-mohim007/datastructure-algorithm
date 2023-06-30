#include<bits/stdc++.h>
using namespace std;
vector<int>weights;
vector<int>value;
vector<vector<int> > memo;
int capacity,n;
int knapsack_recursive(int i,int capacity)
{
  if(i==n||capacity==0){
    return 0;
  }
  if(weights[i]>capacity){
    return knapsack_recursive(i+1,capacity);
  }
  return max(value[i]+knapsack_recursive(i+1,capacity-weights[i]),knapsack_recursive(i+1,capacity));
}
int knapsack_memoization(int i, int capacity)
{
    if (i == n || capacity == 0)
    {
        return 0;
    }
    if (memo[i][capacity] != -1)
    {
        return memo[i][capacity];
    }
    if (weights[i] > capacity)
    {
        memo[i][capacity] = knapsack_memoization(i+1, capacity);
    }
    else
    {
        memo[i][capacity] = max(knapsack_memoization(i+1, capacity), value[i] + knapsack_memoization(i+1, capacity - weights[i]));
    }
    return memo[i][capacity];
}
int bottom_up()
{
    vector<vector<int> > dp(n+1,vector<int>(capacity+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=capacity;j++){
            if (weights[i-1] > j){
                    dp[i][j] = dp[i-1][j];
                    }
        else
        {
            dp[i][j] =  max(dp[i-1][j],value[i-1]+dp[i-1][j-weights[i-1]]);
        }
    }
}
return dp[n][capacity];
}
int main()
{
    cout<<"Enter size:";
    cin>>n;
    cout<<"Enter the weights"<<endl;
    weights.resize(n);
    value.resize(n);
    for(int i=0;i<n;i++)
    {
      cin >> weights[i];
    }
    cout<<"Enter the value"<<endl;
    for(int i=0;i<n;i++)
    {
      cin >> value[i];
    }
    cout<<"Enter the capacity:";
    cin>>capacity;
    memo.resize(n,vector<int>(capacity+1,-1));
    cout << "Recursive result: " << knapsack_recursive(0, capacity) << endl;
    cout << "Memoization result: " << knapsack_memoization(0, capacity) << endl;
    cout << "Bottom up result: " << bottom_up() << endl;
}
