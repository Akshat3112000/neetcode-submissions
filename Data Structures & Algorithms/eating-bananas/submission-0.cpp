class Solution {
public:
    bool f(int m, vector<int>& a, int h)
    {
        int sum = 0;
        for(int &x:a) 
        {
            sum += (m - 1 + x)/m;
        }
        return sum <= h;
    }
    int minEatingSpeed(vector<int>& a, int h) {
        int l = 1;
        int r = INT_MIN;

        for(int &x:a) r = max(r,x);

        while(l < r)
        {
            int m = l + (r - l)/2;
            if(f(m, a, h)) r = m;
            else l = m + 1;
        }
        return r;
    }
};
