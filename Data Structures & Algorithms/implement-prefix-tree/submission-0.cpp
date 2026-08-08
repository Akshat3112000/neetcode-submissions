class PrefixTree {
    struct TrieNode {
        TrieNode *a[26];
        bool isWord;
        TrieNode(bool y)
        {
            this->isWord = y;
            for(int i = 0;  i<26;i++)
            {
                this->a[i] = nullptr;
            }
        }
    };
    TrieNode* trie;
public:
    PrefixTree() {
        this->trie = new TrieNode(0);
    }
    
    void insert(string word) {

        int n = word.length();
        TrieNode* cur = this->trie;
        int i = 0;

        while(i < n - 1 && cur->a[word[i]-'a'])
        {
            cur = cur->a[word[i]-'a'];
            i++;
        }
        for(; i < n - 1;i++)
        {
            cur->a[word[i]-'a'] = new TrieNode(0);
            cur = cur->a[word[i]-'a'];
        }

        if(!cur->a[word[i]-'a'])
        {
            cur->a[word[i]-'a'] = new TrieNode(1);
        }
        else cur -> a[word[i]-'a'] -> isWord = 1;

    }
    
    bool search(string word) {
        int n = word.length();
        TrieNode* cur = this->trie;
        int i = 0;
        while(i < n && cur->a[word[i]-'a'])
        {
            cur = cur->a[word[i]-'a'];
            i++;
        }

        return (i == n) && cur -> isWord;

    }
    
    bool startsWith(string word) {
        int n = word.length();
        TrieNode* cur = this->trie;
        int i = 0;
        while(i < n && cur->a[word[i]-'a'])
        {
            cur = cur->a[word[i]-'a'];
            i++;
        }

        return (i == n);
    }
};
