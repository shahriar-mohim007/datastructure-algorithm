#include<bits/stdc++.h>
using namespace std;
vector<vector<int> >memo;
int len1,len2;
string s1,s2;

int lcs_memoization(int i,int j)
{
    if(i==len1 || j==len2)
    {
        return 0;
    }
    if (memo[i][j]!=-1)
    {
        return memo[i][j];
    }
    int ans = 0;

    if(s1[i]==s2[j])
    {
        ans = 1+lcs_memoization(i+1,j+1);
    }
    else
    {
        ans =  max(lcs_memoization(i+1,j),lcs_memoization(i,j+1));
    }

    memo[i][j] = ans;


   return memo[i][j];
}

int lcs_bottom_up()
{
vector<vector<int> > dp(len1+1,vector<int>(len2+1,0));
for(int i=1;i<=len1;i++){
    for(int j=1;j<=len2;j++){
        if(s1[i-1]==s2[j-1])
        {
            dp[i][j] = 1+dp[i-1][j-1];
        }
        else{
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }

    }

}
return dp[len1][len2];
}

int main()
{

    cin>>s1>>s2;
    len1 = s1.size();
    len2 = s2.size();
    memo.resize(len1+1,vector<int>(len2+1,-1));
    cout<<lcs_memoization(0,0)<<endl;
    cout<<lcs_bottom_up()<<endl;
}
