class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();
        // A[i][j]: ways of trying to enter (i,j) while moving right
        // B[i][j]: ways of trying to enter (i,j) while moving down
        vector<vector<long long>> A(m + 1, vector<long long>(n + 1, 0));
        vector<vector<long long>> B(m + 1, vector<long long>(n + 1, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                long long a = A[i][j], b = B[i][j];
                if (grid[i][j] == 0) {
                    long long ways = (i == 0 && j == 0) ? 1 : (a + b) % MOD;
                    if (i == m - 1 && j == n - 1) return ways % MOD;
                    // move right / down from an empty cell
                    A[i][j + 1] = (A[i][j + 1] + ways) % MOD;
                    B[i + 1][j] = (B[i + 1][j] + ways) % MOD;
                } else {
                    // entered moving right -> reflected down
                    B[i + 1][j] = (B[i + 1][j] + a) % MOD;
                    // entered moving down -> reflected right
                    A[i][j + 1] = (A[i][j + 1] + b) % MOD;
                }
            }
        }
        return 0;
    }
};
