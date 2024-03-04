#include<bits/stdc++.h>
using namespace std;

void printmatrixorder(vector<vector<int>>& bracket,int i,int j)
{
    if(i==j)
    {
        cout<<"A"<<i;
    }
    else
    {
        cout<<"(";
        printmatrixorder(bracket,i,bracket[i][j]);
        printmatrixorder(bracket,bracket[i][j]+1,j);
        cout<<")";
    }

}


void matrixChainMultiplication(vector<int>&dimensions)
{
int n =  dimensions.size();
vector<vector<int>>dp(n,vector<int>(n,0));
vector<vector<int>>bracket(n,vector<int>(n,0));
for(int d=1;d<n-1;d++)
{
    for(int i=1;i<n-d;i++)
    {
        int j = i+d;
        dp[i][j] = INT_MAX;
        for(int k=i;k<j;k++)
        {
            int cost = dp[i][k] + dp[k+1][j] + dimensions[i-1] * dimensions[k] * dimensions[j];
            if(cost<dp[i][j])
            {
                dp[i][j] = cost;
                bracket[i][j] = k;
            }
        }
    }
}
cout << "Minimum cost for matrix chain multiplication: " << dp[1][n - 1] << endl;
cout << "Matrix multiplication order: ";
printmatrixorder(bracket, 1, n - 1);
cout << endl;


}

int main()
{
    int n;
    cin>>n;
    vector<int>dimensions(n+1);
    for(int i=0;i<n+1;i++)
    {
     cin>>dimensions[i];
    }
    matrixChainMultiplication(dimensions);

 
}