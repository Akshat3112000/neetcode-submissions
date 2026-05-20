class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        vector<int> st;

        int ans = 0;

        for(int i = 0; i < a.size(); i++)
        {
            while(st.size()!=0 && a[i] < a[st.back()])
            {
                int v = st.back();
                st.pop_back();
                if(st.size()==0) ans = max(ans, a[v] * i );
                else ans = max(ans, a[v] * (i - st.back() - 1));
            }
            st.push_back(i);
        }
        while(st.size()!=0)
        {
            int v = st.back();
            st.pop_back();
            if(st.empty()) ans = max(ans, a[v] * (int) a.size() );
            else ans = max(ans, a[v] * ((int) a.size() - st.back() - 1));
        }
        return ans;
    }
};
