#include <string>
#include <algorithm>

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // If the required sum exceeds the maximum possible sum (9 * num), return empty string.
        if (num * 9 < sum) {
            return "";
        }
        
        string ans = "";
        
        // Greedily append '9' as long as remaining sum allows
        while (sum >= 9) {
            ans += '9';
            sum -= 9;
        }
        
        // If there is a remainder sum, append it
        if (sum > 0) {
            ans += to_string(sum);
        }
        
        // Fill the rest of the positions with '0' to match `num` digits
        while (ans.length() < num) {
            ans += '0';
        }
        
        return ans;
    }
};
