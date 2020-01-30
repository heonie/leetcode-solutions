class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
    
    bool solve(vector<vector<char>>& board, int row, int col) {
		if (row >= 9 || col >= 9) {
			return true;
		}
		if (board[row][col] == '.') {
			for (int n = 1; n <= 9; n++) {
				if (canPlace(board, row, col, n)) {
					board[row][col] = n + '0';
					int c = col+1;
					int r = row;
					if (c >= 9) {
						r++;
						c = 0;
					}
					if (solve(board, r, c)) {
						return true;
					}
					board[row][col] = '.';
				}
			}
			return false;
		}
		col++;
		if (col >= 9) {
			row++;
			col = 0;
		}
		return solve(board, row, col);
	}
	bool canPlace(vector<vector<char>>& board, int row, int col, int n) {
		for (int i = 0; i < 9; i++) {
			if (board[row][i] == n + '0' || board[i][col] == n + '0') {
				return false;
			}
		}
		int x = col / 3;
		int y = row / 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (board[i + y*3][j + x*3] == n + '0') {
					return false;
				}
			}
		}
		return true;
	}
};
