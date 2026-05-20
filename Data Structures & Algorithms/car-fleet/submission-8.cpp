class Solution {
public:
    int carFleet(int t, vector<int>& p, vector<int>& s) {
        int n = p.size();
        vector<pair<int,double>> a(n);
        for(int i = 0; i < n; i++)
        {
            a[i].first = p[i];
            a[i].second = (double) (t - p[i])/s[i];
        }
        sort(a.begin(),a.end());
        int ans = 1;
        double mx = a.back().second; 
        for(int i = n-1;i >=0;i--)
        {
            if(a[i].second > mx)
            {
                ans++;
                mx = a[i].second;
            }
        }
        return ans;
    }
};
