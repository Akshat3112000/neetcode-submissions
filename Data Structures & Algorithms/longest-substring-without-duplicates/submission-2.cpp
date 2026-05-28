class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == "") return 0;
        unordered_map<char,int> idx;
        int i = 0;
        idx[s[0]] = 0;
        int ans = 1;
        int j;
        for(j = 1; j < s.size(); j++)
        {
            if(idx.find(s[j]) != idx.end() && idx[s[j]] >= i)
            {
                ans = max(ans,j - i);
                i = idx[s[j]] + 1;
            }
            idx[s[j]] = j; 
        }
        return max(ans,j - i);
    }
};
