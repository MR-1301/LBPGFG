// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int findMaxDiff(int [], int n);

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
   	int n;
   	cin>>n;
   	int a[n];
   	for(int i=0;i<n;i++)
   	cin>>a[i];
   	cout<<findMaxDiff(a,n)<<endl;
   }
    return 0;
}


// } Driver Code Ends


/*You are required to complete this method */
int findMaxDiff(int A[], int n)
{
  //Your code here
  vector<int> LS(n),RS(n);
  
  stack<int> st;
  
  for(int i=0;i<n;i++)
  {
      while(!st.empty() and  A[st.top()]>A[i])
      {
          RS[st.top()]=i;
          st.pop();
      }
      
      st.push(i);
  }
  
  while(!st.empty())
  {
      RS[st.top()]=-1;
      st.pop();
  }
  
  for(int i=n-1;i>=0;i--)
  {
      while(!st.empty() and  A[st.top()]>A[i])
      {
          LS[st.top()]=i;
          st.pop();
      }
      
      st.push(i);
  }
  
  while(!st.empty())
  {
      LS[st.top()]=-1;
      st.pop();
  }
  
  int ans=0;
  for(int i=0;i<n;i++)
  {
      int x=LS[i]!=-1?A[LS[i]]:0;
      int y=RS[i]!=-1?A[RS[i]]:0;
      ans=max(ans,abs(x-y));
  }
  return ans;
}