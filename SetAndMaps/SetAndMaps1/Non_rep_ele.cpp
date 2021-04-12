// https://leetcode.com/problems/find-the-duplicate-number/

//my solution
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        
        for(auto x:nums)
        {
            if(mp.find(x)!=mp.end())
                return x;
            mp[x]++;
        }
        return -1;
    }
};


// faster and less memory solution
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(fast!=slow);
        
        fast = nums[0];
        while(fast!=slow){
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};