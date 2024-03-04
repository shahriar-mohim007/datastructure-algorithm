#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>&nums,int l,int m,int r)
{
 int n1 = m-l+1;
 int n2 = r-m;
 vector<int>l1(n1);
 vector<int>r1(n2);

 for(int i=0;i<n1;i++)
 {
    l1[i] = nums[l+i];
  
 }
 for(int i=0;i<n2;i++)
 {
    r1[i] = nums[m+1+i];
 }
int i,j,k;
i=0;
j=0;
k=l;

 while(i<n1&&j<n2)
 {
  if(l1[i]<r1[j])
  {
    nums[k] = l1[i];
    i++;
    k++;
  }
  else
  {
    nums[k] = r1[j];
    j++;
    k++;
  }
 }
 while(i<n1)
 {
    nums[k] = l1[i];
    k++;
    i++;
 }
 while(j<n2)
 {
   nums[k] = r1[j];
    k++;
    j++; 
 }
}
void mergesort(vector<int>&nums,int l,int r)
{
 if (l<r)
 {
    int m = l + (r-l)/2;
    mergesort(nums,l,m);
    mergesort(nums,m+1,r);
    merge(nums,l,m,r);
 }
}
int main()
{
    int elements;
    cin>>elements;
    vector<int>nums(elements);
    for(int i=0;i<elements;i++)
    {
        cin>>nums[i];
    }
    
    mergesort(nums,0,elements-1);
    for(int i=0;i<nums.size();i++)
    {
        cout<<nums[i]<<" ";
    }

}