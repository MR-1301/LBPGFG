// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    static int findPlatform(int arr[], int dep[], int n)
    {
        vector<pair<int,int> > a(n);
        for(int i=0;i<n;i++)
        {
            a[i]={dep[i],arr[i]};
        }

        sort(a.begin(),a.end());
        set<int> s;
        for(int i=0;i<n;i++)
        {
            if(s.empty())
            {
                s.insert(a[i].first);
                continue;
            }
            auto itr=s.lower_bound(a[i].second);
            if(itr == s.begin())
                s.insert(a[i].first);
            else{
                itr--;
                s.erase(itr);
                s.insert(a[i].first);
            }
        }

        return (int)s.size();
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends