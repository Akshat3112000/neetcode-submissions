class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int>s;

        for(int i = 0; i < nums.size(); i++)
        {
            if(s.find(nums[i]) != s.end()){
                return true;
            } else{
                s.insert(nums[i]);
            }
            // cnt[nums[i]]++;
            // if(cnt[nums[i]] > 1) return true;
        }

        return false;
    }
};