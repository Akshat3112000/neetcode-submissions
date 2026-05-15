class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;
        unordered_set<char> open;
        open.insert('(');
        open.insert('[');
        open.insert('{');

        unordered_map<char, char> mp;
        mp[')'] = '(';
        mp[']'] = '[';
        mp['}'] = '{';

        for (char& c : s) {
            if (open.find(c) != open.end())
                st.push(c);
            else if (st.empty() || st.top() != mp[c])
                return false;
            else
                st.pop();
        }
        return st.empty();
    }
};
