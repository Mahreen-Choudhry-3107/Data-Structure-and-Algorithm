/*
1288. Remove Covered Intervals

// solution
**************************************************************

class Solution {
 public:
  int removeCoveredIntervals(vector<vector<int>>& intervals) {
    ranges::sort(intervals, ranges::less{}, [](const vector<int>& interval) {
      const int l = interval[0];
      const int r = interval[1];
      return pair<int, int>{l, -r};
    });

    int ans = 0;
    int prevEnd = 0;

    for (const vector<int>& interval : intervals)
      if (prevEnd < interval[1]) {
        prevEnd = interval[1];
        ++ans;
      }

    return ans;
  }
};

*/