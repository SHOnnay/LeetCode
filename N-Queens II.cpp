class Solution {
public:
    int count = 0;

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
            count++;
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col)) {
                board[row][col] = 'Q';
                solve(board, row + 1);
                board[row][col] = '.'; // backtrack
            }
        }
    }

    int totalNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        solve(board, 0);
        return count;
    }
};
