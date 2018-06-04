class Solution {
    typedef pair<int, int> ii;

    void traverse(vector<vector<char>>& board, int rows, int cols, int y, int x) {
        queue<ii> store;

        store.push(make_pair(y, x));
        board[y][x] = 'M';
        while(!store.empty()) {
            ii coord = store.front();
            store.pop();

            int curY = coord.first;
            int curX = coord.second;
            
            if (curY >= 1 && board[curY - 1][curX] == 'O') {
                board[curY - 1][curX] = 'M';
                store.push(make_pair(curY - 1, curX));
            }
            
            if ((curY + 1) < rows && board[curY + 1][curX] == 'O') {
                board[curY + 1][curX] = 'M';
                store.push(make_pair(curY + 1, curX));
            }
            
            if (curX >= 1 && board[curY][curX - 1] == 'O') {
                board[curY][curX - 1] = 'M';
                store.push(make_pair(curY, curX - 1));
            }
            
            if ((curX + 1) < cols && board[curY][curX + 1] == 'O') {
                board[curY][curX + 1] = 'M';
                store.push(make_pair(curY, curX + 1));
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        if (board.empty())
            return;
            
        int rows = board.size();
        int cols = board[0].size();
        for (int r = 0; r < rows; r++) {
            if (board[r][0] == 'O') {
                traverse(board, rows, cols, r, 0);
            }
            
            if (board[r][cols - 1] == 'O') {
               traverse(board, rows, cols, r, cols - 1);
            }
        }

        for (int c = 1; c < (cols - 1); c++) {
            if (board[0][c] == 'O') {
                traverse(board, rows, cols, 0, c);
            }
            
            if (board[rows - 1][c] == 'O') {
                traverse(board, rows, cols, rows - 1, c);
            }
        }
        
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == 'M') {
                    board[r][c] = 'O';
                } else {
                    board[r][c] = 'X';
                }
            }
        }
    }
};