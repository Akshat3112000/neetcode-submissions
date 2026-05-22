class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        deque<int> dq;
        int n = a.size();
        for (int i = 0; i < k; i++) {
            while(!dq.empty() && a[dq.back()] <= a[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        vector<int> ans;
        ans.push_back(a[dq.front()]);

        for(int i = k; i< n;i++)
        {
            while(!dq.empty() && a[dq.back()] < a[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if(dq.front() == i - k) dq.pop_front();
            ans.push_back(a[dq.front()]);
        }
        return ans;
    }
};
