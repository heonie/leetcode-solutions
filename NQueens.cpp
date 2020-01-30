class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<char>> map(n);
        for(int i=0; i<n; i++) {
            map[i] = vector<char>(n, '.');
        }
        return nqueens(map, n, 0, 0);
    }
    int nqueens(vector<vector<char>> map, int n, int row, int count) {
        if(row == n) {
            return count + 1;
        }
        for(int col=0; col<n; col++) {
            if(canPlace(map, n, row, col)) {
                map[row][col] = 'Q';
                count = nqueens(map, n, row+1, count);
                map[row][col] = '.';
            }
        }
        return count;
    }
    bool canPlace(vector<vector<char>> map, int n, int row, int col) {
        for(int i=1; i<n; i++) {
            if(   row+i < n && col+i < n && map[row+i][col+i] != '.'
               || row+i < n && map[row+i][col] != '.'
               || row+i < n && col-i >= 0 && map[row+i][col-i] != '.'
               || col+i < n && map[row][col+i] != '.'
               || col-i >= 0 && map[row][col-i] != '.'
               || row-i >= 0 && col+i < n && map[row-i][col+i] != '.'
               || row-i >= 0 && map[row-i][col] != '.'
               || row-i >= 0 && col-i >= 0 && map[row-i][col-i] != '.'
              ) {
                return false;
            }
        }
        return true;
    }
};
