class Solution {
    bool isLegal(vector<vector<char>> &grid, int y, int x, vector<vector<bool>> &visited) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (y < 0 || y >= rows || x < 0 || x >= cols)
            return false;

        return grid[y][x] == '1' && !visited[y][x];
    }

    void traverse(vector<vector<char>> &grid, int y, int x, vector<vector<bool>> &visited) {
        visited[y][x] = true;
        
        if (isLegal(grid, y - 1, x, visited)) {
            traverse(grid, y - 1, x, visited);
        }
        
        if (isLegal(grid, y + 1, x, visited)) {
            traverse(grid, y + 1, x, visited);
        }
        
        if (isLegal(grid, y, x - 1 , visited)) {
            traverse(grid, y, x - 1, visited);
        }
        
        if (isLegal(grid, y, x + 1 , visited)) {
            traverse(grid, y, x + 1, visited);
        }
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if (rows == 0)
            return 0;

        int cols = grid[0].size();
        
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        int count = 0;
        for (int y = 0; y < rows; y++) {
            for (int x = 0; x < cols; x++) {
                if (grid[y][x] == '1' && visited[y][x] == false) {
                    count++;
                    traverse(grid, y, x, visited);
                }
            }
        }
        return count;
    }
};