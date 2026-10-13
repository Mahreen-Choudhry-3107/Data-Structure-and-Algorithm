#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    long long maxAlternatingSum(std::vector<int>& nums) {
        // Transform each element to its square
        std::vector<long long> squares;
        for (long long x : nums) {
            squares.push_back(x * x);
        }
        
        // Sort squares in ascending order
        std::sort(squares.begin(), squares.end());
        
        int n = squares.size();
        long long s1 = 0; // Sum of smaller half (subtracted)
        long long s2 = 0; // Sum of larger half (added)
        
        // First n / 2 elements go to minus slots
        for (int i = 0; i < n / 2; ++i) {
            s1 += squares[i];
        }
        
        // Remaining elements go to plus slots
        for (int i = n / 2; i < n; ++i) {
            s2 += squares[i];
        }
        
        return s2 - s1;
    }
};
