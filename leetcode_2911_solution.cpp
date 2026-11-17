class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        // cost[i][j]: min changes to make s[i..j] a semi-palindrome
        vector<vector<int>> cost(n, vector<int>(n, INF));

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int len = j - i + 1;
                int best = INF;
                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;
                    int changes = 0;
                    for (int g = 0; g < d; g++) {
                        // group: i+g, i+g+d, ... ; compare ends moving inward
                        int cnt = len / d;
                        int l = 0, r = cnt - 1;
                        while (l < r) {
                            if (s[i + g + l * d] != s[i + g + r * d]) changes++;
                            l++;
                            r--;
                        }
                    }
                    best = min(best, changes);
                }
                cost[i][j] = best;
            }
        }

        // dp[p][i]: min changes to split first i chars into p parts
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));
        dp[0][0] = 0;
        for (int p = 1; p <= k; p++) {
            for (int i = 1; i <= n; i++) {
                for (int j = p - 1; j < i; j++) {
                    if (dp[p - 1][j] == INF || cost[j][i - 1] == INF) continue;
                    dp[p][i] = min(dp[p][i], dp[p - 1][j] + cost[j][i - 1]);
                }
            }
        }
        return dp[k][n];
    }
};
