/*
3312. Sorted GCD Pair Queries

// solution:
**************************************************************************

class Solution {
 public:
  vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
    const int maxNum = ranges::max(nums);
    vector<int> ans;
    vector<int> countDivisor(maxNum + 1);
    vector<long> countGcdPair(maxNum + 1);
    vector<long> prefixCountGcdPair{0};

    for (const int num : nums)
      for (int i = 1; i * i <= num; ++i)
        if (num % i == 0) {
          ++countDivisor[i];
          if (i != num / i)
            ++countDivisor[num / i];
        }

    for (int gcd = maxNum; gcd >= 1; --gcd) {
      countGcdPair[gcd] =
          countDivisor[gcd] * static_cast<long>(countDivisor[gcd] - 1) / 2;
      for (int largerGcd = 2 * gcd; largerGcd <= maxNum; largerGcd += gcd)
        countGcdPair[gcd] -= countGcdPair[largerGcd];
    }

    for (int gcd = 1; gcd <= maxNum; ++gcd)
      prefixCountGcdPair.push_back(prefixCountGcdPair.back() +
                                   countGcdPair[gcd]);

    for (const long query : queries)
      ans.push_back(getNthGcdPair(query, prefixCountGcdPair));

    return ans;
  }

 private:
  int getNthGcdPair(long query, const vector<long>& prefixCountGcdPair) {
    int l = 1;
    int r = prefixCountGcdPair.size() - 1;
    while (l < r) {
      const int m = (l + r) / 2;
      if (prefixCountGcdPair[m] < query + 1)
        l = m + 1;
      else
        r = m;
    }
    return l;
  }
};
*/