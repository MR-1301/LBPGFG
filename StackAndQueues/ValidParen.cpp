// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Function to return if the paranthesis are balanced or not
bool ispar(string x)
{
    // Your code here
    int curr = 0;
    int n = x.size();
    map<char, int> mp;
    mp['{'] = 1;
    mp['}'] = -1;
    mp['('] = 2;
    mp[')'] = -2;
    mp['['] = 3;
    mp[']'] = -3;
    for (int i = 0; i < n; i++)
    {
        curr += mp[x[i]];
        if (curr < 0)
            return false;
    }

    if (curr == 0)
        return true;
    return false;
}

// { Driver Code Starts.

int main()
{
    int t;
    string a;
    cin >> t;
    while (t--)
    {
        cin >> a;
        if (ispar(a))
            cout << "balanced" << endl;
        else
            cout << "not balanced" << endl;
    }
} // } Driver Code Ends