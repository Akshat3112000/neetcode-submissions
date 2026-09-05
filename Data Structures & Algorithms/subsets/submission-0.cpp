class Solution {
public:
    vector<vector<int>> subsets(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> res = f(a,n);
        return res;
    }

    vector<vector<int>> f(vector<int>& a, int n)
    {
        if(n == 0)
        {
            vector<int> u;
            vector<vector<int>> ans;
            ans.push_back(u);
            return ans;
        }
        vector<vector<int>> res = f(a,n-1);
        int m = res.size();

        for(int i = 0;i <m;i++)
        {
            vector<int> v = res[i];
            v.push_back(a[n-1]);
            res.push_back(v);
        }
        
        return res;
    }
};
