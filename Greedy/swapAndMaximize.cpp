// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

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
        for(int i=0;i<n;++i)
            cin>>arr[i];
        cout<<maxSum(arr,n)<<endl;
    }
    return 0;
}// } Driver Code Ends


long long int maxSum(int arr[], int n)
{
    sort(arr,arr+n);
    int first=0;
    int second=n-1;

    long long ans=0;
    bool flag= true;
    int cnt=n-1;
    int temp=arr[0];
    while(cnt--)
    {
//        cout<<arr[first]<<" "<<arr[second]<<endl;
        ans+=abs(arr[first]-arr[second]);
        if(flag)
        {
            swap(first,second);
            second++;
            flag= false;
        }
        else{
            swap(first,second);
            second--;
            flag=true;
        }
    }
    ans+=abs(arr[second]-temp);
    return ans;
}