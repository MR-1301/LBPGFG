// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int Maximize(int a[],int n)
    {
        sort(a,a+n);
        long long ans=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++)
        {
            long long lol=a[i];
            lol*=i;
            ans=(ans+(lol)%mod)%mod;
        }

        return (int) ans;
    }
};

// { Driver Code Starts.
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.Maximize(a,n)<<endl;
    }
}  // } Driver Code Ends