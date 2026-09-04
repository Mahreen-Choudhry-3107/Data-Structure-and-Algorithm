#include <vector>
#include <algorithm>

class Solution {
public:
    int firstStableIndex(std::vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return -1;

        // Precompute the suffix minimums
        std::vector<int> right(n);
        right[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            right[i] = std::min(right[i + 1], nums[i]);
        }
        int left = nums[0];
        for (int i = 0; i < n; ++i) {
            left = std::max(left, nums[i]);
            
            if (left - right[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};
