// { Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// The main function to convert infix expression
//to postfix expression
string infixToPostfix(string s)
{
    // Your code here
    //precendes
    unordered_map<char,int> mp;
    
    mp['-']=1;
    mp['+']=1;
    mp['*']=3;
    mp['/']=3;
    mp['^']=4;
    mp['(']=0;
    mp[')']=0;
    string ans="";
    int n=s.size();
    stack<char> st;
    for(int i=0;i<n;i++)
    {
        if(mp.find(s[i])==mp.end())
        ans+=s[i];
        else{
            if(s[i]=='(')
            st.push('(');
            else if(s[i]==')')
            {
                while(st.top()!='(')
                {
                    ans+=st.top();      
                    st.pop();
                }
                st.pop();
            }
            else{
                while(!st.empty() and mp[st.top()]>=mp[s[i]])
                {
                    ans+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
    }
    
    while(!st.empty())
    {
        ans+=st.top();
        st.pop();
    }
    return ans;
}


// { Driver Code Starts.
//Driver program to test above functions
int main()
{
    int t;
    // cin>>t;
    // cin.ignore(INT_MAX, '\n');
    t=1;
    while(t--)
    {
        string exp;
        cin>>exp;
        cout<<infixToPostfix(exp)<<endl;
    }
    return 0;
}
  // } Driver Code Ends