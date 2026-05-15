#include <cstdlib>

class Solution {
public:
    
    int evalRPN(vector<string>& a) {
        stack<int> st;
        for(string &c:a){
            int x,y;
            if(c == "+") 
            {
                x = st.top();
                st.pop();
                y = st.top();
                st.pop();
                st.push(x+y);
            }
            else if( c == "-")
            {
                x = st.top();
                st.pop();
                y = st.top();
                st.pop();
                st.push(y-x);
            }
            else if( c == "*")
            {
                x = st.top();
                st.pop();
                y = st.top();
                st.pop();
                st.push(x*y);
            }
            else if( c == "/")
            {
                x = st.top();
                st.pop();
                y = st.top();
                st.pop();
                st.push(y/x);
            }
            else
            {
                st.push(stoi(c));
            }
        }
        return st.top();
    }
};
