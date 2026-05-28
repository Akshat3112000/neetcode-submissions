class Solution {
public:
    int findMin(vector<int> &a) {
        int l,h;
        l = 0;
        h = a.size() - 1;

        while(l < h)
        {
            int m = l + (h-l)/2;
            if(a[m] < a[0]) h = m;
            else l = m + 1;
        }
        return min(a[h],a[0]);
    }
};
