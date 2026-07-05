/*
1301. Number of Paths with Max Score

//solution
****************************************************************************

class Solution {
 public:
  vector<int> pathsWithMaxScore(vector<string>& board) {
    constexpr int kMod = 1'000'000'007;
    constexpr int kDirs[3][2] = {{0, 1}, {1, 0}, {1, 1}};
    const int n = board.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    vector<vector<int>> count(n + 1, vector<int>(n + 1));

    dp[0][0] = 0;
    dp[n - 1][n - 1] = 0;
    count[n - 1][n - 1] = 1;

    for (int i = n - 1; i >= 0; --i)
      for (int j = n - 1; j >= 0; --j) {
        if (board[i][j] == 'S' || board[i][j] == 'X')
          continue;
        for (const auto& [dx, dy] : kDirs) {
          const int x = i + dx;
          const int y = j + dy;
          if (dp[i][j] < dp[x][y]) {
            dp[i][j] = dp[x][y];
            count[i][j] = count[x][y];
          } else if (dp[i][j] == dp[x][y]) {
            count[i][j] += count[x][y];
            count[i][j] %= kMod;
          }
        }
        if (dp[i][j] != -1 && board[i][j] != 'E') {
          dp[i][j] += board[i][j] - '0';
          dp[i][j] %= kMod;
        }
      }

    return {dp[0][0], count[0][0]};
  }
};
*/