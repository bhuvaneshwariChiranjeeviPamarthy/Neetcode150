#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
private:
    void bfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited){
        //For memory
        queue<pair<int, int>> q;
        //Mark visited.
        visited[i][j] = true;
        q.push({i, j});

        int rows = grid.size(), cols = grid[0].size();

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while(!q.empty()){
            //Expand the island.
            int row = q.front().first, col = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++){
                int nr = row + dr[k];
                int nc = col + dc[k];

                if (nr >= 0 && nr < rows &&
                    nc >= 0 && nc < cols &&
                    grid[nr][nc] == '1' &&
                    !visited[nr][nc]) {

                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()){
            return 0;
        }
        int islands = 0;
        int row = grid.size();
        int column = grid[0].size();

        //Visited array for tracking.
        vector<vector<bool>> visited(row, vector<bool> (column, false));

        for(int r = 0; r < row; r++){
            for(int c = 0; c < column; c++){
                if(grid[r][c] == '1' && visited[r][c] == false){
                    //Traverse & Mark it visited.
                    bfs(r, c, grid, visited);
                    islands += 1;
                }
            }
        }
        return islands;
    }
};
