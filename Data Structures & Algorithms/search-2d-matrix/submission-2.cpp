class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int k) {
        
        int m = a[0].size();

        int l = 0;
        int h = a.size() * m - 1;

        while(l <= h)
        {
            int mid = l + (h-l)/2;
            if(a[mid/m][mid % m] == k) return 1;
            if(a[mid/m][mid % m] < k) l = mid + 1;
            else h = mid - 1;
        }

        return 0;
        
    }
};
