class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> cnt;

        for(int &x:nums)
        {
            cnt[x]++;
            if(cnt[x] > 1) return true;
        }

        return false;
    }
};