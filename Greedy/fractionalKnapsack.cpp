// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
public:
        static bool cmp1(pair<int,int> &a,pair<int,int> &b)
        {
            return (double)a.first/a.second > (double )b.first/b.second;
        }

        //Function to get the maximum total value in the knapsack.
        double fractionalKnapsack(int W, Item arr[], int n)
        {
            vector<pair<int,int> > a;
            for(int i=0;i<n;i++)
            {
                a.push_back({arr[i].value,arr[i].weight});
            }
            sort(a.begin(),a.end(), cmp1);
            double ans=0;
            for(int i=0;i<n;i++)
            {
                if(W==0)
                    break;
                if(a[i].second<=W)
                {
                    ans+=a[i].first;
                    W-=a[i].second;
                }
                else{
                    double lol=(double)a[i].first/(double)a[i].second;
                    ans+=(double)W*lol;
                    W=0;
                }
            }

            return ans;
        }


};


// { Driver Code Starts.
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE
    int t;
    //taking testcases
    cin>>t;
    cout<<setprecision(2)<<fixed;
    while(t--){
        //size of array and weight
        int n, W;
        cin>>n>>W;

        Item arr[n];
        //value and weight of each item
        for(int i=0;i<n;i++){
            cin>>arr[i].value>>arr[i].weight;
        }

        //function call
        Solution ob;
        cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends