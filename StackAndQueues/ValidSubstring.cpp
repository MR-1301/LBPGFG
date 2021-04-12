// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        stack<int> st;
        int maxi=0;
        int n=s.size();
        st.push(-1);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else{
                if(st.empty())
                st.push(i);
                else{
                    if(st.top()!=-1 and s[st.top()]=='(')
                    {
                        st.pop();
                        maxi=max(maxi,i-st.top());
                    }
                    else
                    {
                        st.push(i);    
                    }
                }
            }
        }
        
        
        return maxi;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}
  // } Driver Code Ends