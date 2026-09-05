class Solution {
    struct TrieNode {
        TrieNode* child[26]{};
        int wordIdx = -1;
    };

    TrieNode* root = new TrieNode();

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    void insert(const string& word, int idx) {
        TrieNode* cur = root;

        for (char c : word) {
            int x = c - 'a';

            if (!cur->child[x]) {
                cur->child[x] = new TrieNode();
            }

            cur = cur->child[x];
        }

        cur->wordIdx = idx;
    }

    void dfs(vector<vector<char>>& board, int x, int y, TrieNode* node, vector<string>& words,
             vector<string>& result) {
        char c = board[x][y];
        int idx = c - 'a';

        TrieNode* next = node->child[idx];

        if (!next) return;

        // We found a complete word
        if (next->wordIdx != -1) {
            result.push_back(words[next->wordIdx]);

            // Prevent finding the same word again
            next->wordIdx = -1;
        }

        // Mark current cell as visited
        board[x][y] = '#';

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size() ||
                board[nx][ny] == '#') {
                continue;
            }

            dfs(board, nx, ny, next, words, result);
        }

        // Backtrack
        board[x][y] = c;
    }

   public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            insert(words[i], i);
        }

        vector<string> result;

        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dfs(board, i, j, root, words, result);
            }
        }

        return result;
    }
};