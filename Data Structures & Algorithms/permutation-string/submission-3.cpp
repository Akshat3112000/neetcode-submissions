class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        
        int cnt[26] = {0};
        int k = s1.size();

        // Step 1: Initialize frequencies
        for (char &c : s1) cnt[c - 'a']++;
        for (int i = 0; i < k; i++) cnt[s2[i] - 'a']--;

        // Step 2: Count how many initial characters match 0
        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 0) matches++;
        }
        if (matches == 26) return true;

        // Step 3: Slide the window
        for (int i = k; i < s2.size(); i++) {
            int r = s2[i] - 'a';     // Character entering on the right
            int l = s2[i - k] - 'a'; // Character leaving on the left

            // Handle the character ENTERING the window (its count decreases)
            if (cnt[r] == 0) matches--; // It was a match, but now it won't be
            cnt[r]--;
            if (cnt[r] == 0) matches++; // It just became a perfect match

            // Handle the character LEAVING the window (its count increases)
            if (cnt[l] == 0) matches--; // It was a match, but now it won't be
            cnt[l]++;
            if (cnt[l] == 0) matches++; // It just became a perfect match

            // Check if all 26 are matched in O(1) time
            if (matches == 26) return true;
        }

        return false;
    }
};