class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        // Build bitmask with seats 1-10
        for (auto &r : reservedSeats) {
            int row = r[0], seat = r[1];
            mp[row] |= (1 << seat);
        }

        int ans = 0;

        for (auto &[row, mask] : mp) {
            // Check blocks using proper bitmasks
            bool left  = (mask & ((1 << 6) - (1 << 2))) == 0;  // seats 2,3,4,5
            bool right = (mask & ((1 << 10) - (1 << 6))) == 0; // seats 6,7,8,9
            bool mid   = (mask & ((1 << 8) - (1 << 4))) == 0;  // seats 4,5,6,7

            if (left && right) {
                ans += 2;
            } else if (left || mid || right) {
                ans += 1;
            }
        }

        // Rows without reservations can seat 2 groups each
        ans += (n - mp.size()) * 2;

        return ans;
    }
};
