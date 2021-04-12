bool cmp(vector<int> &a,vector<int> &b)
{
    if(a[0]==b[0])
        return a[1]<b[1];
    return a[0]<b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(),a.end(),cmp);
        
        stack<vector<int> > s;
        
        for(int i=0;i<a.size();i++)
        {
            if(s.empty())
            {
               s.push(a[i]); 
            }
            else{
                vector<int> temp=s.top();
                s.pop();
                if(temp[1]>=a[i][0])
                {
                    temp[1]=max(temp[1],a[i][1]);
                    s.push(temp);
                }
                else{
                    
                    s.push(temp);
                    s.push(a[i]);
                }
            }
        }
        
        vector<vector<int> > ans;
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};