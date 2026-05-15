#include <cstdlib>

class Solution {
public:
    
    int evalRPN(vector<string>& a) {
        set<string> s = {"+","-","*","/"};
        stack<int> st;
        for(string &c:a){
            if(s.find(c) != s.end()) 
            {
                int x,y;
                x = st.top();
                st.pop();
                y = st.top();
                st.pop();
                if(c == "+") st.push(x+y);
                if(c == "-") st.push(y-x);
                if(c == "*") st.push(x*y);
                if(c == "/") st.push(y/x);
            }
            else
            {
                st.push(stoi(c));
            }
        }
        return st.top();
    }
};
