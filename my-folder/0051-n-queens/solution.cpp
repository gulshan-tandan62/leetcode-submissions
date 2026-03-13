class Solution {
    bool isSafe(int i, int j, int n, vector<string>& board) {
        for (int k = j - 1; k >= 0; k--) {
            if (board[i][k] == 'Q')
                return false;
        }

        for (int l = i - 1, m = j - 1; l >= 0 && m >= 0; l--, m--) {

            if (board[l][m] == 'Q')
                return false;
        }
        for (int l = i + 1, m = j - 1; l < n && m >= 0; l++, m--) {

            if (board[l][m] == 'Q')
                return false;
        }
        return true;
    }
    void placeQueens(int col, int n, vector<string>& board,
                     vector<vector<string>>& res) {
        if (col == n) {
            res.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isSafe(i, col, n, board)) {
                board[i][col] = 'Q';
                placeQueens(col + 1, n, board, res);
                board[i][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));

        placeQueens(0, n, board, res);

        return res;
    }
};
