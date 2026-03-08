// question 26 (leetcode problem # 128. Longest Consecutive Sequence)
/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.
Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
*/

//sol

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> seen(nums.begin(), nums.end());

        for (int num : seen) {
            if (seen.find(num - 1) != seen.end())
                continue;

            int length = 1;
            while (seen.find(num + 1) != seen.end()) {
                num++;
                length++;
            }

            ans = max(ans, length);
        }

        return ans;
    }
};



// #include <iostream>
// #include <vector>
// #include <unordered_set>
// #include <algorithm>
// using namespace std;

// class Solution {
//  public:
//   int longestConsecutive(vector<int>& nums) {
//     int ans = 0;
//     unordered_set<int> seen{nums.begin(), nums.end()};

//     for (int num : seen) {
//       if (seen.contains(num - 1))
//         continue;
//       int length = 1;
//       while (seen.contains(++num))
//         ++length;
//       ans = max(ans, length);
//     }

//     return ans;
//   }
// };