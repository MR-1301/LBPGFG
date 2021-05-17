// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends



class Solution {
public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x) {
        stack<char> s;
        for (int i=0;i<x.size();i++) {
            if (s.empty()== true or x[i]=='(' or x[i]=='[' or x[i]=='{')
            {
                s.push(x[i]);
            }
            else if ((x[i]==')' and s.top()=='(') or (x[i]=='}' and s.top()=='{') or (x[i]==']' and s.top()=='[')) {

                s.pop();
            }
            else
            {
                s.push(x[i]);
            }
        }
        return s.empty();
    }

};

// { Driver Code Starts.

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.ispar(a))
            cout << "balanced" << endl;
        else
            cout << "not balanced" << endl;
    }
}  // } Driver Code Ends