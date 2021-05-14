// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> a){
        // code here
        int maxi=a[N-1];
        int curr=N-1;
        int i;
        for(i=N-2;i>=0;i--)
        {
            if(a[i]>maxi)
            {
                maxi=a[i];
            }
            else{
                int mini=INT_MAX;
                for(int j=i+1;j<N;j++)
                {
                    if(a[j]<mini and a[j]>a[i])
                    {
                        mini=a[j];
                        curr=j;
                    }

                }
                swap(a[curr],a[i]);
                sort(a.begin()+i+1,a.end());
                break;
            }
        }

        if(i==-1)
        {
            sort(a.begin(),a.end());
        }
        return a;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];

        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends