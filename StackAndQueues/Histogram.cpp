// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return Maximum Rectangular area in a histogram
// arr[]: input array
// n: size of array

class Solution
{
    public:
    long long getMaxArea(long long A[], int n){
    // Your code here
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
        RS[st.top()]=n;
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

    long long ans=0;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,(RS[i]-LS[i]-1)*A[i]);
    }    

    return ans;
}
};



// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends