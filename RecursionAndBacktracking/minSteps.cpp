// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    static int solve(int S,int i,int D)
    {
        if(abs(S)>D)
            return INT_MAX;

        if(S==D)
            return i-1;

        return min(solve(S+i,i+1,D),solve(S-i,i+1,D));
    }

    int minSteps(int D){
        return solve(0,1,D);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int D;
        cin>>D;

        Solution ob;
        cout<<ob.minSteps(D)<<"\n";
    }
    return 0;
}  // } Driver Code Ends