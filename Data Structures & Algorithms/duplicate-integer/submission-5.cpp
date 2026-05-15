class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int>cnt;

        for(int i = 0; i < nums.size(); i++)
        {
            cnt[nums[i]]++;
            if(cnt[nums[i]] > 1) return true;
        }

        return false;
    }
};