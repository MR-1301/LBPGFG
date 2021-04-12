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

int op(int a,int b,char ch)
{
    int res;
    switch (ch)
    {
        case '+':
            res=a+b;
            break;
        case '-':
            res=a-b;
            break;
        case '*':
            res=a*b;
            break;
        case '/':
            res=a/b;
            break;
        case '^':
            res=pow(a,b);
            break;
        default:
            break;
    }

    return res;
}

int AEE(string s)
{
    stack<int> a;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='+' or s[i]=='-' or s[i]=='/' or s[i]=='*' or s[i]=='^')
        {
            int x=a.top();
            a.pop();
            int y=a.top();
            a.pop();
            a.push(op(y,x,s[i]));
        }
        else
        {
            a.push(s[i]-'0');
        }
    }

    return a.top();
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
        cout<<exp<<endl;
        string eva=infixToPostfix(exp);
        cout<<AEE(eva);
    }
    return 0;
}
  // } Driver Code Ends