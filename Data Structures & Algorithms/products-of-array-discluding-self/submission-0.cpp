class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int lp[n], rp[n];

        lp[0] = 1;
        rp[n-1] = 1;

        for(int i = 1; i < n; i++)
        {
            lp[i] = nums[i-1] * lp[i - 1];
            rp[n - 1 - i] = nums[n - i] * rp[n - i];
        }

        vector<int> ans;

        for(int i = 0; i < n;i++)
        {
            ans.push_back(lp[i] * rp[i]);
        }
        return ans;
    }
};
