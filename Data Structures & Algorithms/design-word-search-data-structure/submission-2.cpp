class WordDictionary {
    struct TrieNode {
        TrieNode* a[26];
        bool isWord;
        TrieNode() {
            isWord = 0;
            for (int i = 0; i < 26; i++) {
                a[i] = nullptr;
            }
        }
    };
    TrieNode* trie;

   public:
    WordDictionary() { trie = new TrieNode(); }

    void addWord(string word) {
        int n = word.length();
        TrieNode* cur = trie;
        int i = 0;

        while (i < n && cur->a[word[i] - 'a']) {
            cur = cur->a[word[i] - 'a'];
            i++;
        }
        for (; i < n; i++) {
            cur->a[word[i] - 'a'] = new TrieNode();
            cur = cur->a[word[i] - 'a'];
        }

        cur->isWord = 1;
    }

    bool search(string word) {
        queue<TrieNode*> q;
        q.push(trie);
        for (char c : word) {
            int n = q.size();
            if (n == 0) break;
            while (n--) {
                TrieNode* node = q.front();
                q.pop();
                if (c != '.') {
                    if (node->a[c - 'a']) q.push(node->a[c - 'a']);
                    continue;
                }
                for (int i = 0; i < 26; i++) {
                    if (node->a[i]) q.push(node->a[i]);
                }
            }
        }
        while (!q.empty()) {
            TrieNode* node = q.front();
            q.pop();
            if (node->isWord) return 1;
        }
        return 0;
    }
};
