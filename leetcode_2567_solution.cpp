class Solution {
 public:
  int minimizeSum(vector<int>& nums) {
    ranges::sort(nums);
    const int n = nums.size();
    const int highOfChangingTwoMins = nums.back() - nums[2];
    const int highOfChangingTwoMaxs = nums[n - 3] - nums[0];
    const int highOfChangingMinAndMax = nums[n - 2] - nums[1];
    return min({highOfChangingTwoMins, highOfChangingTwoMaxs,
                highOfChangingMinAndMax});
  }
};
