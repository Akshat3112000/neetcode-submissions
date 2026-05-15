class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";

        for(string &st:strs)
        {
            s += to_string( (int) st.size()) + "#" + st;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        for(int i = 0; i < s.size(); i++)
        {
            string sz = "";
            while(s[i] != '#')
            {
                sz.push_back(s[i]);
                i++;
            }
            int l = stoi(sz);
            ans.push_back(s.substr(i+1,l));
            i+=l;
        }
        return ans;
    }
};
