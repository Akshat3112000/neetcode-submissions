class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n,m;
        n = a.size();
        m = b.size();
        if(m < n) return findMedianSortedArrays(b,a);
        int t = (n+m+1)/2;
        int l = 0;
        int h = n;
        bool odd = (n + m) % 2;
        int al,bl,ar,br;
        int a1,b1;
        while(l <= h)
        {
            a1 = l + ((h - l) >> 1);
            b1 = t - a1;
            if(b1 > m) 
            {
                l = a1 + 1;
                continue;
            }

            if(a1 > 0) al = a[a1 - 1];
            else al = INT_MIN;
            if(b1 > 0) bl = b[b1 - 1];
            else bl = INT_MIN;
            if(a1 < n) ar = a[a1];
            else ar = INT_MAX;
            if(b1 < m) br = b[b1];
            else br = INT_MAX;

            if(al <= br && bl <= ar)
            {
                if(odd) return max(al,bl);
                else return (max(al,bl) + min(ar,br))/2.0;
            }
            else if(al > br) h = a1 - 1;
            else l = a1 + 1;

        }

        return 0.0;
    }
};
