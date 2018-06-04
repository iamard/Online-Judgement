class Solution {
    void traverse(vector<vector<int>>& matrix, int y, int x, vector<vector<bool>> &visited) {
        if (!visited[y][x]) {
            visited[y][x] = true;
        
            int value = matrix[y][x];
            int rows = matrix.size();
            int cols = matrix[0].size();

            int u = y - 1;
            if ((u >= 0) && (value <= matrix[u][x])) {
                traverse(matrix, u, x, visited);
            }
        
            int l = x - 1;
            if ((l >= 0) && (value <= matrix[y][l])) {
                traverse(matrix, y, l, visited);
            }
        
            int d = y + 1;
            if ((d < rows) && (value <= matrix[d][x])) {
                traverse(matrix, d, x, visited);
            }
        
            int r = x + 1;
            if ((r < cols) && (value <= matrix[y][r])) {
                traverse(matrix, y, r, visited);
            }
        }
    }

public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows <= 0)
            return {};
        
        int cols = matrix[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
        for (int c = 0; c < cols; c++) {
            traverse(matrix, 0, c, pacific);
            traverse(matrix, rows - 1, c, atlantic);
        }

        for (int r = 0; r < rows; r++) {
            traverse(matrix, r, 0, pacific);
            traverse(matrix, r, cols - 1, atlantic);
        }
        
        vector<pair<int, int>> result;
        for (int y = 0; y < rows; y++) {
            for (int x = 0; x < cols; x++) {
                if (pacific[y][x] && atlantic[y][x]) {
                    result.push_back(make_pair(y, x));
                }
            }
        }
        
        return result;
    }
};