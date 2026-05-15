class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int>cnt;

        for(int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            cnt[x]++;
            if(cnt[x] > 1) return true;
        }

        return false;
    }
};