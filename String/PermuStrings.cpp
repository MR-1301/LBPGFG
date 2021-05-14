// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string permutation;
    vector<string> ans1;
    vector<bool> chosen;
    string OG;
    int size;
public:
    void solve()
    {
        if(permutation.size()==size)
        {
            ans1.push_back(permutation);
            return;
        }

        for(int i=0;i<size;i++)
        {
            if(chosen[i]== false)
            {
                chosen[i]= true;
                permutation.push_back(OG[i]);
                solve();
                permutation.pop_back();
                chosen[i]= false;
            }
        }

    }


    vector<string> find_permutation(string S)
    {

        size=S.size();
        OG=S;
        chosen.resize(size, false);
        solve();
        sort(ans1.begin(),ans1.end());
        return ans1;
    }
};



// { Driver Code Starts.
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE

    int t;
    cin >> t;
    while(t--)
    {
        string S;
        cin >> S;

        Solution ob;
        vector<string> ans= ob.find_permutation(S);
        for(auto i: ans)
        {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends