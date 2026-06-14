class Solution {
public:
    int findDuplicate(vector<int>& a) {
        int n = a.size() - 1;

        int slow, fast;
        slow = a[0];
        fast = a[a[0]];

        while(fast != slow)
        {
            slow = a[slow];
            fast = a[a[fast]];
        }

        fast = 0;
        while(fast != slow)
        {
            slow = a[slow];
            fast = a[fast];
        }

        return fast;
    }
};
