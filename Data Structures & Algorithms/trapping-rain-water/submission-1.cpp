class Solution {
public:
    int trap(vector<int>& a) {
        stack<int> st;
        int ans = 0;
        for(int i = 0; i<a.size();i++)
        {
            
            while(!st.empty() && a[i] > a[st.top()])
            {
                int v = st.top();
                st.pop();
                if(st.empty()) break;
                int l = st.top();
                ans += (i - l - 1) * (min(a[l],a[i]) - a[v]);
            }
            st.push(i);
        }
        return ans;
    }
};
