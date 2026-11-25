#include <vector>
#include <unordered_map>
#include <cstdint>

using namespace std;

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        
        // Double hashing parameters to avoid hash collisions
        const long long BASE1 = 1315423911LL, MOD1 = 1000000007LL;
        const long long BASE2 = 1000003LL,    MOD2 = 1000000009LL;

        auto hasUniqueSubarray = [&](int len) -> bool {
            long long p1 = 1, p2 = 1;
            for (int i = 0; i < len - 1; ++i) {
                p1 = (p1 * BASE1) % MOD1;
                p2 = (p2 * BASE2) % MOD2;
            }

            long long h1 = 0, h2 = 0;
            // Store combined 64-bit hash -> frequency
            unordered_map<uint64_t, int> freq;
            freq.reserve(n - len + 1);

            for (int i = 0; i < n; ++i) {
                // Remove leftmost element when window exceeds size `len`
                if (i >= len) {
                    long long out = nums[i - len];
                    h1 = (h1 - (out * p1) % MOD1 + MOD1) % MOD1;
                    h2 = (h2 - (out * p2) % MOD2 + MOD2) % MOD2;
                }

                // Shift and add current element
                h1 = (h1 * BASE1 + nums[i]) % MOD1;
                h2 = (h2 * BASE2 + nums[i]) % MOD2;

                if (i >= len - 1) {
                    uint64_t combinedHash = (static_cast<uint64_t>(h1) << 32) | static_cast<uint64_t>(h2);
                    freq[combinedHash]++;
                }
            }

            for (const auto& [hashVal, count] : freq) {
                if (count == 1) return true;
            }
            return false;
        };

        int low = 1, high = n, ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (hasUniqueSubarray(mid)) {
                ans = mid;
                high = mid - 1; // Try to find an even smaller length
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
