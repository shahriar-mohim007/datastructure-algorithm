#include<bits/stdc++.h>
using namespace std;
vector<int>memo;
int fibonacchi_recursive(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    return fibonacchi_recursive(n-1)+fibonacchi_recursive(n-2);
}
int fibonacchi_memorization(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    if (memo[n]!=-1)
       return memo[n];
    
    memo[n]=fibonacchi_memorization(n-1)+fibonacchi_memorization(n-2);
    return memo[n];
}
int iterative(int n)
{
memo[0]=0;
memo[1]=1;
for(int i=2;i<=n;i++)
{
    memo[i] = memo[i-1]+memo[i-2];
}
return memo[n];
}
int main()
{
    int n;
    cin>>n;
    cout<<fibonacchi_recursive(n)<<endl;
    memo.resize(n+1,-1);
    cout<<fibonacchi_memorization(n)<<endl;
    memo.resize(n+1,0);
    cout<<iterative(n)<<endl;
}
