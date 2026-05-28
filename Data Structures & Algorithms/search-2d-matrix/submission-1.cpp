class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int k) {
        int l,h;
        int n = a.size(), m = a[0].size();

        l = 0;
        h = n * m - 1;

        while(l <= h)
        {
            int mid = l + ((h-l) >> 1);
            if(a[mid/m][mid % m] == k) return 1;
            if(a[mid/m][mid % m] < k) l = mid + 1;
            else h = mid - 1;
        }

        return 0;
        
    }
};
