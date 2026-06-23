// Solution
/*
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1e9 + 7;
        int m = r - l + 1;
        
        if (n == 1) return m;
        if (m == 1) return 0;  // No valid arrays with only one value
        
        // Use 1D arrays for better cache performance
        vector<long long> up(m, 0), down(m, 0);
        
        // Length 1
        for (int i = 0; i < m; i++) {
            up[i] = 1;
            down[i] = 1;
        }
        
        // Length 2
        vector<long long> new_up(m, 0), new_down(m, 0);
        long long prefix = 0;
        for (int i = 0; i < m; i++) {
            new_up[i] = prefix;
            prefix = (prefix + up[i]) % MOD;
        }
        
        long long suffix = 0;
        for (int i = m - 1; i >= 0; i--) {
            new_down[i] = suffix;
            suffix = (suffix + down[i]) % MOD;
        }
        
        up = move(new_up);
        down = move(new_down);
        
        // Length 3 to n
        for (int len = 3; len <= n; len++) {
            vector<long long> next_up(m, 0), next_down(m, 0);
            
            // For up: previous must be down and prev < curr
            long long running = 0;
            for (int i = 0; i < m; i++) {
                next_up[i] = running;
                running = (running + down[i]) % MOD;
            }
            
            // For down: previous must be up and prev > curr
            running = 0;
            for (int i = m - 1; i >= 0; i--) {
                next_down[i] = running;
                running = (running + up[i]) % MOD;
            }
            
            up = move(next_up);
            down = move(next_down);
        }
        
        long long ans = 0;
        for (int i = 0; i < m; i++) {
            ans += up[i] + down[i];
            if (ans >= MOD) ans %= MOD;
        }
        
        return ans % MOD;
    }
};
*/