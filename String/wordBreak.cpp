// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int wordBreak(string A, vector<string> &B);

// User code will be pasted here

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        cout<<wordBreak(line, dict)<<"\n";
    }
}
// } Driver Code Ends


//User function template for C++

// A : given string to search
// B : vector of available strings

unordered_map<string,bool> dp;
bool solve(string s)
{
    if(s.size()==0)
        return true;

    if(dp.find(s)!=dp.end())
        return dp[s];

    bool poss=false;


    for(int i=0;i<(int)s.size()-1;i++)
    {
//        cout<<s.substr(0,i+1)<<" "<<s.substr(i+1,n-i-1)<<endl;
        int n=s.size();
        bool x= solve(s.substr(0,i+1));
        bool y=solve(s.substr(i+1,n-i-1));
        poss|=(x and y);
        if(poss)
            break;
    }
    dp[s]=poss;
    return poss;
}


int wordBreak(string A, vector<string> &B) {
    //code here
    int n=A.size();
    for(string s:B)
    {
        dp[s]=true;
    }

    if(solve(A))
        return 1;
    else
        return 0;
}