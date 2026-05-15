class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        sort(a.begin(),a.end());
        vector<vector<int>> ans;
        int n = a.size();

        for(int k = 0; k < n; k++)
        {
            if(a[k] > 0) break;

            int i = k+1;
            int j = n - 1;

            while(i < j)
            {
                int s = a[i] + a[j] + a[k];
                if(s == 0)
                {
                    ans.push_back({a[k],a[i],a[j]});
                    while(i < j && a[i] == a[i+1]) i++;
                    while(i < j && a[j] == a[j-1]) j--;
                    i++;
                    j--;
                }
                else if(s > 0) j--;
                else i++;
            }
            while(k < n && a[k] == a[k+1]) k++;
        }
        return ans;
    
    }
};
