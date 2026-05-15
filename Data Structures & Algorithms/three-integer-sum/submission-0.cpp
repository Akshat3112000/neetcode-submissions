class Solution {
public:
    struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        size_t seed = 0;
        for (int i : v) {
            // A common way to combine hashes
            seed ^= hash<int>{}(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
    };
    vector<vector<int>> threeSum(vector<int>& a) {
        int n = a.size();
        unordered_set<vector<int>,VectorHash> ans;

        sort(a.begin(),a.end());

        for(int k = 0; k < n; k++)
        {
            if (a[k] > 0) break;
            int i = k+1;
            int j = n - 1;

            while(i < j)
            {
                int s = a[i] + a[j] + a[k];
                if(s == 0) 
                {
                    ans.insert({a[k], a[i], a[j]});
                    i++;
                    j--;
                }
                else if (s > 0) j--;
                else i++;
            }
        }
        vector<vector<int>> result;

        for(const vector<int> &v:ans)
        {
            result.push_back(v);
        }
        return result;
    }
};
