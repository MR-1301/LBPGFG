// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include<bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job
{
    int id;	 // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};


// } Driver Code Ends

/*
struct Job
{
    int id;	 // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

class Solution
{
public:
    static bool cmp(pair<int,int> &a,pair<int,int> &b)
    {
        return a.first>b.first;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        // your code here
        int maxi=INT_MIN;

        vector<pair<int,int> > a(n);
        for(int i=0;i<n;i++)
        {
            a[i]=(make_pair(arr[i].profit,arr[i].dead));
            maxi=max(arr[i].dead,maxi);
        }


        set<int> s;
        for(int i=-1;i<maxi;i++)
        {
            s.insert(i);
        }

        sort(a.begin(),a.end(),cmp);
        int profit=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
//            cout<<a[i].first<<" "<<a[i].second<<endl;
            auto itr=s.upper_bound(a[i].second-1);
            itr--;

            if(itr!=s.begin()){
                s.erase(itr);
                ans++;
                profit+=a[i].first;
            }
        }

        vector<int> res;
        res.push_back(ans);
        res.push_back(profit);
        return res;
    }
};

// { Driver Code Starts.
// Driver program to test methods
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE
    int t;
    //testcases
    cin >> t;

    while(t--){
        int n;

        //size of array
        cin >> n;
        Job arr[n];

        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


// } Driver Code Ends