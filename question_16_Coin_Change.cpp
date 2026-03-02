// Question # 16 => Leetcode Problem(518. Coin Change II)
/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.
Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
*/

// Solution
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount + 1, 0);
        dp[0] = 1;

        for (const int coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                dp[i] += dp[i - coin];
            }
        }

        return (int)dp[amount];
    }
};

int main(){
  Solution obj;
  int amount = 5;
  vector<int> coins = {1, 2, 5};

  int result = obj.change(amount, coins);
  cout << result;

  return 0;
}

// Output => 4