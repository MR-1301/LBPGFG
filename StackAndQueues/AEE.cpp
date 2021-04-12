// { Driver Code Starts
// C++ program to evaluate value of a postfix expression
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
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

// The main function that returns value of a given postfix expression
int evaluatePostfix(string S)
{
    // Your code here
    stack<int> a;
    for(int i=0;i<S.size();i++)
    {
        if(S[i]=='+' or S[i]=='-' or S[i]=='/' or S[i]=='*' or S[i]=='^')
        {
            int x=a.top();
            a.pop();
            int y=a.top();
            a.pop();
            a.push(op(y,x,S[i]));
        }
        else
        {
            a.push(S[i]-'0');
        }
    }

    return a.top();
}


// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
    
    cout<<evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends