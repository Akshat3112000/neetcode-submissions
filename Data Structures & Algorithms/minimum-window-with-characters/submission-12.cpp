class Solution {
   public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.size() < t.size()) return "";
        unordered_map<char, int> frq;
        int cnt = 0;
        for (char& c : t) frq[c]++;

        int i = 0;
        int start = 0;
        int l = INT_MAX;
        for (int j = 0; j < s.size(); j++) {
            if (frq[s[j]] > 0) cnt++;

            frq[s[j]]--;

            while (cnt == t.size()) {
                if ((j - i + 1) < l) {
                    start = i;
                    l = j - i + 1;
                }
                frq[s[i]]++;
                if (frq[s[i]] > 0) cnt--;
                i++;
            }
        }
        return l == INT_MAX ? "" : s.substr(start, l);
    }
};
