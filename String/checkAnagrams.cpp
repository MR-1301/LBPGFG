// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    public:
    /*  Function to check if two strings are anagram
    *   a, b: input string
    */
    bool isAnagram(string a, string b){
        // Your code here
        vector<int> fa(26,0);
        int n=a.size();
        int m=b.size();
        
        if(n!=m)
        return false;

        for(int i=0;i<n;i++)
        {
            fa[a[i]-'a']++;
            fa[b[i]-'a']--;
        }

        for(int i=0;i<26;i++)
        {
            // cout<<i<<" ";
            if(fa[i]!=0)
            return false;
        }

        return true;
    }

};

// { Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}
  // } Driver Code Ends