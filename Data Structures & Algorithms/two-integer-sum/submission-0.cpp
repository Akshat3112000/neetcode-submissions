class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int i = 0;
        for(int &x:nums)
        {
            if(mp.find(x) != mp.end()) 
            {
                return vector<int>{mp[x],i};
            }
            else
            {
                mp.insert({target - x, i});
            }
            i++;
        }
        return vector<int>();
    }
};
