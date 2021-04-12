// { Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// The main function to convert infix expression
//to postfix expression
string postToPre(string s)
{
    // Your code here
    //precendes
    // cout<<s;
    unordered_map<char,int> mp;
    mp['-']=1;
    mp['+']=1;
    mp['*']=3;
    mp['/']=3;
    mp['^']=4;

    stack<string> st;
    // cout<<s;
    for(int i=0;i<s.size();i++)
    {
        if(mp.find(s[i])==mp.end())
        {
            string temp="";
            temp+=s[i];
            st.push(temp);
        }
        else
        {
            string opa1=st.top();
            st.pop();
            string opa2=st.top();
            st.pop();

            st.push(s[i]+opa2+opa1);
        }
    }

    return st.top();
}


// { Driver Code Starts.
//Driver program to test above functions
int main()
{
    int t;
    // cin>>t;
    t=1;
    // cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string exp;
        cin>>exp;
        // cout<<exp;
        cout<<postToPre(exp)<<endl;
    }
    return 0;
}
  // } Driver Code Ends