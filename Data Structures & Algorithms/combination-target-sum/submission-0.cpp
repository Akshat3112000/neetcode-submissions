class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& a, int t) {
        vector<vector<int>> res;
        vector<int> cur;
        f(a,t,0,cur,res);
        return res;
    }

    void f(vector<int>& a, int t, int i, vector<int>& cur, vector<vector<int>>& res)
    {
        if(t == 0)
        {
            res.push_back(cur);
            return;
        }
        if(i == a.size() || t < 0)
        {
            return;
        }

        f(a,t,i+1,cur,res);
        
        cur.push_back(a[i]);
        f(a,t - a[i],i,cur,res);
        cur.pop_back();
    }

};
