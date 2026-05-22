class Solution {
   public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.size() < t.size()) return "";
        unordered_map<char, int> frq;
        int cnt = 0;
        for (char& c : t) frq[c]++;

        int i = 0;
        while (i < s.size() && frq.find(s[i]) == frq.end()) i++;
        int j = i;
        int start = -1;
        int l = INT_MAX;
        while (j < s.size()) {
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
            j++;
        }
        if (start == -1) return "";
        return s.substr(start, l);
    }
};
