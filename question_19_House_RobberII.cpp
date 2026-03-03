// Question # 19 => Leetcode problem (213. House Robber II)
/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
*/

//Solution
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.empty())
      return 0;
    if (nums.size() == 1)
      return nums[0];

    auto rob = [&](int l, int r) {
      int prev1 = 0;  // dp[i - 1]
      int prev2 = 0;  // dp[i - 2]

      for (int i = l; i <= r; ++i) {
        const int dp = max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = dp;
      }

      return prev1;
    };

    return max(rob(0, nums.size() - 2), rob(1, nums.size() - 1));
  }
};

// Output => 3