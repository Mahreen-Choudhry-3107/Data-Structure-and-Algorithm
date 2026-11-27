class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        const int F = 1500;
        vector<int> cnt(F + 1, 0);
        int m = INT_MAX;
        for (auto& it : items) {
            cnt[it[0]]++;
            m = min(m, it[1]);
        }
        // multiples[f] = number of items whose factor is a multiple of f
        vector<int> mult(F + 1, 0);
        for (int f = 1; f <= F; f++)
            for (int k = f; k <= F; k += f)
                mult[f] += cnt[k];

        vector<int> dp(budget + 1, 0); // at most b spent
        for (auto& it : items) {
            int f = it[0], p = it[1];
            if (p > budget) continue;
            int val = 1 + (mult[f] - 1);
            for (int b = budget; b >= p; b--)
                dp[b] = max(dp[b], dp[b - p] + val);
        }

        int ans = 0;
        for (int b = 0; b <= budget; b++)
            ans = max(ans, dp[b] + (budget - b) / m);
        return ans;
    }
};
