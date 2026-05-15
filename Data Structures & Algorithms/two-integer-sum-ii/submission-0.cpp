class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t) {
        int j = a.size() - 1;
        int i = 0;

        while(i < j)
        {
            if(a[i] + a[j] == t)
                return vector<int>{i+1,j+1};
            if(a[i] + a[j] > t) j--;
            else i++;
        }
        return vector<int>();
    }
};
