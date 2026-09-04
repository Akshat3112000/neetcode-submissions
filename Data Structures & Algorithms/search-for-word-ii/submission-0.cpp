class Solution {
    struct TrieNode {
        TrieNode* a[26];
        int idx;
        TrieNode() {
            idx = -1;
            for (int i = 0; i < 26; i++) {
                a[i] = nullptr;
            }
        }
    };
    TrieNode* trie;

   public:
    Solution() { trie = new TrieNode(); }
    void insert(string word, int index) {
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

        cur->idx = index;
    }
    void dfs(vector<vector<char>>& board, vector<string>& words, int x, int y,
             vector<vector<bool>>& vis, int l, vector<string>& res, TrieNode* cur) {
        if (l == 0) return;
        if (cur->a[board[x][y] - 'a']) {
            vis[x][y] = true;
            cur = cur->a[board[x][y] - 'a'];
            if (cur->idx != -1) {
                res.push_back(words[cur->idx]);
                cur->idx = -1;
            }
        } else {
            return;
        }

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        // Try all 4 directions
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            // Check bounds and whether already visited
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && !vis[nx][ny]) {
                dfs(board, words, nx, ny, vis, l - 1, res, cur);
            }
        }

        vis[x][y] = false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int l = 0;
        for (int i = 0; i < words.size(); i++) {
            insert(words[i], i);
            l = max(l, (int) words[i].size());
        }
        vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size(), 0));
        vector<string> res;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, words, i, j, vis, l, res, trie);
            }
        }
        return res;
    }
};
