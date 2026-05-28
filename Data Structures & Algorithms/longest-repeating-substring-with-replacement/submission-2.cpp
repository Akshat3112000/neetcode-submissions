class Solution {
public:
    int characterReplacement(string s, int k) {
        int cnt[26] = {0};

        int i = 0;
        int ans = 1;
        int mx = 0;
        for(int j = 0;j < s.size(); j++)
        {
            cnt[s[j] -'A']++;
            mx = max(mx,cnt[s[j] -'A']);
            while((j-i+1) - mx > k)
            {
                cnt[s[i] -'A']--;
                i++;
            }
            ans = max(ans,(j-i+1));
        }
        return ans;
    }
};
