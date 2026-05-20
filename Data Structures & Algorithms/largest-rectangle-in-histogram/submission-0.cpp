class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        stack<int> st;

        int ans = 0;

        for(int i = 0; i < a.size(); i++)
        {
            while(!st.empty() && a[i] < a[st.top()])
            {
                int v = st.top();
                st.pop();
                if(st.empty()) ans = max(ans, a[v] * i );
                else ans = max(ans, a[v] * (i - st.top() - 1));
            }
            st.push(i);
        }
        while(!st.empty())
        {
            int v = st.top();
            st.pop();
            if(st.empty()) ans = max(ans, a[v] * (int) a.size() );
            else ans = max(ans, a[v] * ((int) a.size() - st.top() - 1));
        }
        return ans;
    }
};
