class Solution {
public:
    int maxProfit(vector<int>& a) {
        int ans = 0;
        int mn = a[0];

        for(int i = 1; i < a.size(); i++)
        {
            mn = min(mn,a[i]);
            ans = max(a[i] - mn,ans);
        }
        return ans;
    }
};
