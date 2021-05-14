// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
    string findSubString(string s)
    {
        vector<int> fa(256,0);
        int n=s.size();
        int cnt=0;
        for (int i = 0; i < n; ++i)
        {
            fa[s[i]]++;
            if(fa[s[i]]==1)
                cnt++;
        }

        int l=0;
        int curr=0;
        int mini=n;
        int left=0;
        int right=n-1;
        vector<int> fa1(256,0);
//        cout<<cnt<<"----\n";
        for(int i=0;i<n;i++)
        {
            fa1[s[i]]++;

            if(fa1[s[i]]==1)
            {
//                cout<<s[i]<<" ";
                curr++;
            }

//            cout<<i<<":"<<s[i]<<endl;
            if(curr==cnt)
            {
//                cout<<i<<endl;
                while(fa1[s[l]]>1){
                    fa1[s[l]]--;
                    l++;
                }
                if(i-l+1<mini)
                {
                    mini=i-l+1;
                    left=l;
                    right=i;
                }
            }
        }
        string ans;
        for(int i=left;i<=right;i++)
        {
            ans.push_back(s[i]);
        }

        return ans;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE

    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str).size() << endl;
    }
    return 0;
}  // } Driver Code Ends