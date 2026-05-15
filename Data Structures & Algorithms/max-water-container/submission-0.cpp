class Solution {
public:
    int maxArea(vector<int>& a) {
        int i = 0;
        int j = a.size() - 1;

        int ans = 0;
        while(i < j)
        {
            ans = max((j - i) * min(a[i],a[j]),ans);
            if(a[i] == a[j])
            {
                i++;
                j--;
            }
            else if(a[i] < a[j]) i++;
            else j--;
        }
        return ans;
    }
};
