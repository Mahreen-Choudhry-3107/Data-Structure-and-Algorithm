// Question # 01
/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 
Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

*/

// Solution

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int tar) {
        unordered_map<int, int> m;

        for(int i = 0; i < arr.size(); i++){
            int first = arr[i];
            int second = tar - first;

            if(m.find(second) != m.end()){
                return {m[second], i};
            }

            m[first] = i;
        }

        return {};
    }
};

int main() {
    Solution s;
    vector<int> arr = {2,7,11,15};
    int target = 9;

    vector<int> result = s.twoSum(arr, target);

    for(int x : result)
        cout << x << " ";

    return 0;
}

// Output
// 0 1
