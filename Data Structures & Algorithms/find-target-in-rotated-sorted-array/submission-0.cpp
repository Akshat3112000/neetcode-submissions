class Solution {
public:
    int search(vector<int>& a, int k) {
        int l = 0;
        int h = a.size() - 1;

        while(l <= h)
        {
            int m = l + (h-l)/2;
            if(a[m] == k) return m;
            if(a[l] <= a[m])
            {
                if(k >= a[l] && k < a[m]) h = m - 1;
                else l = m+1;
            }
            else
            {
                if(k > a[m] && k <= a[h]) l = m + 1;
                else h = m - 1;
            }
        }
        return -1;
    }
};
