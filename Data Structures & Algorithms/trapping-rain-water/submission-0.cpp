class Solution {
public:
    int trap(vector<int>& a) {
        int l = 0;
        int r = a.size() - 1;
        int lmx = 0;
        int rmx = 0;
        int ans = 0;

        while(l < r)
        {
            if(a[l] < a[r])
            {
                lmx = max(lmx,a[l]);
                ans += lmx - a[l];
                l++;
            }
            else 
            {
                rmx = max(rmx,a[r]);
                ans += rmx - a[r];
                r--;
            }
        }
        return ans;
    }
};
