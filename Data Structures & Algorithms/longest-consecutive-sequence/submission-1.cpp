class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (int& x : nums) {
            s.insert(x);
        }
        int ans = 0;
        for (int x : nums) {
            if (s.find(x - 1) == s.end()) {
                int l = 1;
                while (s.find(++x) != s.end()) l++;
                ans = max(ans, l);
            }
        }
        return ans;
    }
};
