class Solution {
public:
    bool isAlphanumeric(char &c)
    {
        return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
    }
    bool isPalindrome(string s) {
        int i = 0;
        while(!isAlphanumeric(s[i])) i++;
        int j = s.size() - 1;
        while(!isAlphanumeric(s[j])) j--;

        while(i < j)
        {
            if(tolower(s[i]) != tolower(s[j])) return 0;
            i++;
            while(!isAlphanumeric(s[i])) i++;
            j--;
            while(!isAlphanumeric(s[j])) j--;
        }
        return 1;
    }
};
