class Solution {
   public:
    string count_sort(string& s) {
        int cnt[26] = {0};

        for (char& c : s) {
            cnt[c - 'a']++;
        }
        string st = "";

        for (int i = 0; i < 26; i++)
        {
            while(cnt[i]--) st.push_back('a' + i);
        }
        return st;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        string st;
        for(string &s:strs)
        {
            st = count_sort(s);
            if(mp.find(st) != mp.end())
            {
                mp[st].push_back(s);
            }
            else
            {
                mp[st] = vector<string>{s};
            }
        }
        vector<vector<string>> ans;
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            ans.push_back(it->second);
        }
        return ans;
    }
};
