class Solution {
public:
    vector<vector<string>> results;

    bool isSafe(vector<vector<char>>& board, int row, int col) {
        int n = board.size();

        // check column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }

        // check upper left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // check upper right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    void solve(vector<vector<char>>& board, int row) {
        int n = board.size();
        if (row == n) {
            vector<string> solution;
            for (int i = 0; i < n; i++) {
                string rowStr(board[i].begin(), board[i].end());
                solution.push_back(rowStr);
            }
            results.push_back(solution);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (isSafe(board, row, j)) {
                board[row][j] = 'Q';
                solve(board, row + 1);
                board[row][j] = '.'; // backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        solve(board, 0);
        return results;
    }
};
