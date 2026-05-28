class Solution {
public:
    int search(vector<int>& a, int k) {
        int l,h;
        l = 0;
        h = a.size() - 1;
        while(l <= h)
        {
            int m = l + ((h - l) >> 1);
            if(a[m] == k) return m;
            if(a[m] < k) l = m + 1;
            else h = m - 1;
        }
        return -1;
    }
};
