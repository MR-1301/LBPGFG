int getPairsCount(int arr[], int n, int k) {
        unordered_map<int,int> mp;
        
        int x;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            x=arr[i];
            if(mp.find(k-x)!=mp.end())
            ans+=mp[k-x];
            
            mp[x]++;
        }
        
        return ans;
    }