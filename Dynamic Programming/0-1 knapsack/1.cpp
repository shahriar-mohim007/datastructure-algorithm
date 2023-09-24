#include<bits/stdc++.h>
using namespace std;
vector<int>weights;
vector<int>values;
vector<vector<int> >memo;
int capacity,n;
int bottom_up()
{
  vector<vector<int > >dp(n+1,vector<int>(capacity+1,0));
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=capacity;j++)
    {
       if(weights[i-1]>j)
       {
        dp[i][j] = dp[i-1][j];
       }
       else
       {
        dp[i][j] = max(dp[i-1][j],values[i-1]+dp[i-1][j-weights[i-1]]);
       }
    }
  }
  return dp[n][capacity];
}
int knapsack_memoization(int i,int capacity)
{
   
    if(i==n||capacity==0)
    {
        return 0;
    }
if(weights[i]>capacity)
{
    return knapsack_memoization(i+1,capacity);
}
if(memo[i][capacity]!=-1)
{
    
    return memo[i][capacity];
}
memo[i][capacity] = max(values[i]+knapsack_memoization(i+1,capacity-weights[i]),knapsack_memoization(i+1,capacity));
return memo[i][capacity];
}
int knapsack_recursive(int i,int capacity)
{
if(i==n||capacity==0)
  {
    return 0;
  }
  if(weights[i]>capacity){
    return knapsack_recursive(i+1,capacity);
  }
  return max(values[i]+knapsack_recursive(i+1,capacity-weights[i]),knapsack_recursive(i+1,capacity));
}
int main()
{
cout<<"Enter Size"<<endl;

cin>>n;
weights.resize(n);
values.resize(n);
cout<<"Enter the weights"<<endl;
for(int i=0;i<n;i++)
{
    cin>>weights[i];
}
cout<<"Enter the value"<<endl;
for(int i=0;i<n;i++)
{
    cin>>values[i];
}

cout<<"Enter the capacity:";
cin>>capacity;
cout << "Recursive result: " << knapsack_recursive(0, capacity) <<endl;
memo.resize(n+1,vector<int>(capacity+1,-1));
cout<<"Memoization result: "<<knapsack_memoization(0,capacity)<<endl;
cout << "Bottom up result: " << bottom_up() << endl;
}