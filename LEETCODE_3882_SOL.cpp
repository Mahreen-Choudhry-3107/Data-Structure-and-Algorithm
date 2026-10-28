class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bitset<1024>>> dp(m, vector<bitset<1024>>(n));

        dp[0][0][grid[0][0]] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                int v = grid[i][j];
                bitset<1024> from;
                if (i > 0) from |= dp[i - 1][j];
                if (j > 0) from |= dp[i][j - 1];
                for (int x = 0; x < 1024; x++) {
                    if (from[x]) dp[i][j][x ^ v] = 1;
                }
            }
        }

        for (int x = 0; x < 1024; x++) {
            if (dp[m - 1][n - 1][x]) return x;
        }
        return -1;
    }
};
