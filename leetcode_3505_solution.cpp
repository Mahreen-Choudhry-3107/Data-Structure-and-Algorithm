class Solution {
 public:
  long long minOperations(vector<int>& nums, int x, int k) {
    const vector<long> minOps = getMinOps(nums, x);
    vector<vector<long>> mem(nums.size() + 1, vector<long>(k + 1, -1));
    return minOperations(nums, x, 0, k, minOps, mem);
  }

 private:
  static constexpr long kInf = LONG_MAX / 2;

  long minOperations(const vector<int>& nums, int x, int i, int k,
                     const vector<long>& minOps, vector<vector<long>>& mem) {
    if (k == 0)
      return 0;
    if (i == nums.size())
      return kInf;
    if (mem[i][k] != -1)
      return mem[i][k];
    const long skip = minOperations(nums, x, i + 1, k, minOps, mem);
    const long pick =
        i + x <= nums.size()
            ? minOps[i] + minOperations(nums, x, i + x, k - 1, minOps, mem)
            : kInf;
    return mem[i][k] = min(skip, pick);
  }

  vector<long> getMinOps(const vector<int>& nums, int x) {
    vector<long> minOps;
    multiset<int> lower;
    multiset<int> upper;
    long lowerSum = 0;
    long upperSum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (lower.empty() || nums[i] <= *lower.rbegin()) {
        lower.insert(nums[i]);
        lowerSum += nums[i];
      } else {
        upper.insert(nums[i]);
        upperSum += nums[i];
      }
      if (i >= x) {
        const int outNum = nums[i - x];
        if (const auto it = lower.find(outNum); it != lower.cend()) {
          lower.erase(it);
          lowerSum -= outNum;
        } else {
          upper.erase(upper.find(outNum));
          upperSum -= outNum;
        }
      }
      if (lower.size() < upper.size()) {
        const int val = *upper.begin();
        upper.erase(upper.begin());
        lower.insert(val);
        upperSum -= val;
        lowerSum += val;
      } else if (lower.size() - upper.size() > 1) {
        const int val = *lower.rbegin();
        lower.erase(prev(lower.end()));
        upper.insert(val);
        lowerSum -= val;
        upperSum += val;
      }
      if (i >= x - 1) {
        const int median = *lower.rbegin();
        const long ops = (median * lower.size() - lowerSum) +
                         (upperSum - median * upper.size());
        minOps.push_back(ops);
      }
    }
    return minOps;
  }
};
