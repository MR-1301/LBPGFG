// { Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


/* Node of a doubly linked list */
class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        // code here
        list<int> DLL;
        unordered_map<int, list<int>::iterator> mp;
        int ans=0;
        for(int i=0;i<N;i++)
        {
            if(mp.find(pages[i])!=mp.end())
            {
                DLL.erase(mp[pages[i]]);
                DLL.push_back(pages[i]);
                auto ptr=DLL.end();
                mp[pages[i]]=--ptr;
            }
            else
            {
                ans++;
                if(DLL.size()==C)
                {
                    auto front=DLL.begin();
                    mp.erase(*front);
                    DLL.erase(front);
                    DLL.push_back(pages[i]);
                    auto ptr=DLL.end();
                    mp[pages[i]]=--ptr;
                }
                else{
                    DLL.push_back(pages[i]);
                    auto ptr=DLL.end();
                    mp[pages[i]]=--ptr;
                }
            }

        }

        return ans;
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
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;

        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}  // } Driver Code Ends