class Solution {
public:
    int f(int &i)
    {
        if(i > 1000) return 1000 - i;
        return i;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int cnt[2001] = {0};

        for(int &x:nums)
        {
            if(x < 0) cnt[1000 - x]++;
            else cnt[x]++;
        }

        priority_queue<pair<int,int>> pq;
        for(int i = 0; i<2001;i++)
        {
            pq.push({cnt[i],f(i)});
        }

        vector<int> ans;
        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
