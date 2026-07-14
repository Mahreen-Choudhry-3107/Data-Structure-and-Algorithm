/*
// 3336. Find the Number of Subsequences With Equal GCD

// solution:

class Solution {
 public:
  int subsequencePairCount(vector<int>& nums) {
    const int maxNum = ranges::max(nums);
    vector<vector<vector<int>>> mem(
        nums.size(),
        vector<vector<int>>(maxNum + 1, vector<int>(maxNum + 1, -1)));
    return subsequencePairCount(nums, 0, 0, 0, mem);
  }

 private:
  static constexpr int kMod = 1'000'000'007;


  int subsequencePairCount(const vector<int>& nums, int i, int x, int y,
                           vector<vector<vector<int>>>& mem) {
    if (i == nums.size())
      return x > 0 && x == y;
    if (mem[i][x][y] != -1)
      return mem[i][x][y];
    const int skip = subsequencePairCount(nums, i + 1, x, y, mem);
    const int take1 =
        subsequencePairCount(nums, i + 1, gcd(x, nums[i]), y, mem);
    const int take2 =
        subsequencePairCount(nums, i + 1, x, gcd(y, nums[i]), mem);
    return mem[i][x][y] = (static_cast<long>(skip) + take1 + take2) % kMod;
  }
};
*/