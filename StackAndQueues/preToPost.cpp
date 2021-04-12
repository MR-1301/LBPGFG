// { Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// The main function to convert infix expression
//to postfix expression
string preToPost(string s)
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
    reverse(s.begin(),s.end());
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
            string temp=st.top();
            st.pop();
            temp+=st.top()+s[i];
            st.pop();
            st.push(temp);
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
        cout<<preToPost(exp)<<endl;
    }
    return 0;
}
  // } Driver Code Ends