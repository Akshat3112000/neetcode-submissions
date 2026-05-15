#include <cstdlib>

class Solution {
public:
    
    int evalRPN(vector<string>& a) {
        vector<int> st;
        for(string &c:a){
            int x,y;
            if(c == "+") 
            {
                x = st.back();
                st.pop_back();
                y = st.back();
                st.pop_back();
                st.push_back(x+y);
            }
            else if( c == "-")
            {
                x = st.back();
                st.pop_back();
                y = st.back();
                st.pop_back();
                st.push_back(y-x);
            }
            else if( c == "*")
            {
                x = st.back();
                st.pop_back();
                y = st.back();
                st.pop_back();
                st.push_back(x*y);
            }
            else if( c == "/")
            {
                x = st.back();
                st.pop_back();
                y = st.back();
                st.pop_back();
                st.push_back(y/x);
            }
            else
            {
                st.push_back(stoi(c));
            }
        }
        return st.back();
    }
};
