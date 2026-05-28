class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return 0;
        int cnt[26];

        for(char &c:s1) cnt[c - 'a']++;
        int k = s1.size();

        for(int i = 0; i < k; i++)
        {
            cnt[s2[i] - 'a']--;
        }
        int j = 0;
        while(j < 26 && cnt[j] == 0) j++;
        if(j == 26) return true;

        for(int i = k; i < s2.size(); i++)
        {
            cnt[s2[i] - 'a']--;
            cnt[s2[i-k] - 'a']++;
            j = 0;
            while(j < 26 && cnt[j] == 0) j++;
            if(j == 26) return true;
        }

        return 0;   
    }
};
