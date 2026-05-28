class Solution {
public:
    int characterReplacement(string s, int k) {
        int cnt[26] = {0};

        int i = 0;
        int ans = 1;
        for(int j = 0;j < s.size(); j++)
        {
            cnt[s[j] -'A']++;
            int mx = INT_MIN;
            for(int &x:cnt) mx = max(mx,x);
            while((j-i+1) - mx > k)
            {
                cnt[s[i] -'A']--;
                i++;
                mx = INT_MIN;
                for(int &x:cnt) mx = max(mx,x);
            }
            ans = max(ans,(j-i+1));
        }
        return ans;
    }
};
