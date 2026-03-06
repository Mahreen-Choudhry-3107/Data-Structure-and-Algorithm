// Question # 24 => Leetcode(417. Pacific Atlantic Water Flow)
/*
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.
*/

//sol
#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        if (heights.empty() || heights[0].empty()) return result;
 
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        queue<pair<int, int>> pacQueue;
        queue<pair<int, int>> atlQueue;
        
        for (int i = 0; i < m; ++i) {
            pacQueue.push({i, 0});
            pacific[i][0] = true;
            atlQueue.push({i, n - 1});
            atlantic[i][n - 1] = true;
        }
        
        for (int j = 0; j < n; ++j) {
            pacQueue.push({0, j});
            pacific[0][j] = true;
            atlQueue.push({m - 1, j});
            atlantic[m - 1][j] = true;
        }
        
        bfs(pacQueue, pacific, heights);
        bfs(atlQueue, atlantic, heights);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
 
private:
    void bfs(queue<pair<int, int>>& q, vector<vector<bool>>& ocean, vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (auto& dir : directions) {
                int newRow = r + dir.first;
                int newCol = c + dir.second;
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n 
                    && !ocean[newRow][newCol] && heights[newRow][newCol] >= heights[r][c]) {
                    ocean[newRow][newCol] = true;
                    q.push({newRow, newCol});
                }
            }
        }
    }
};

//input => heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]

// output => [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
