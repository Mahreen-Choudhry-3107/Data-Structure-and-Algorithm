// Question # 20 => Leetcode (91. Decode Ways)
/*
You have intercepted a secret message encoded as a string of numbers. The message is decoded via the following mapping:

"1" -> 'A'

"2" -> 'B'

...

"25" -> 'Y'

"26" -> 'Z'

However, while decoding the message, you realize that there are many different ways you can decode the message because some codes are contained in other codes ("2" and "5" vs "25").

For example, "11106" can be decoded into:

"AAJF" with the grouping (1, 1, 10, 6)
"KJF" with the grouping (11, 10, 6)
The grouping (1, 11, 06) is invalid because "06" is not a valid code (only "6" is valid).
Note: there may be strings that are impossible to decode.

Given a string s containing only digits, return the number of ways to decode it. If the entire string cannot be decoded in any valid way, return 0.

The test cases are generated so that the answer fits in a 32-bit integer.


Example 1:

Input: s = "12"

Output: 2

Explanation:

"12" could be decoded as "AB" (1 2) or "L" (12).
*/


//solution
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        
        if(s[0] == '0') return 0;

        vector<int> dp(s.length() + 1);
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= s.length(); i++){
            int one = stoi(s.substr(i-1,1));
            int two = stoi(s.substr(i-2,2));

            if(one >= 1)
                dp[i] += dp[i-1];

            if(two >= 10 && two <= 26)
                dp[i] += dp[i-2];
        }

        return dp[s.length()];
    }
};


int main() {
    Solution obj;
    string s = "12";
    cout << obj.numDecodings(s);

    return 0;
}

//Output => 2

// class Solution {
/* public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        
        vector<int> dp(n);
        
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for(int i = 2; i < n; i++){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        
        return dp[n-1];
    }
};
*/



