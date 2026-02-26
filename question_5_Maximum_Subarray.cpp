// Question # 5 => Leetcode problem # 53(Maximum Subarray)
/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
*/

//Solution
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int sum = 0;

        int n= nums.size();
        for(int i=0; i<n; i++){
            sum += nums[i];
            maxSum = max(maxSum, sum);
            if(sum<0){
                sum = 0;
            }
        } 
        return maxSum;
        
    }
};

int main() {

    Solution obj;  

    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    int result = obj.maxSubArray(nums);

    cout << "Maximum Subarray Sum: " << result;

    return 0;
}


//Output
// 6