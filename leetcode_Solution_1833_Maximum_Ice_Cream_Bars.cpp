
//Solution

/*


class Solution {
 public:
  int maxIceCream(vector<int>& costs, int coins) {
    ranges::sort(costs);

    for (int i = 0; i < costs.size(); ++i)
      if (coins >= costs[i])
        coins -= costs[i];
      else
        return i;

    return costs.size();
  }
};


*/

/*
case 1:D
output:
costs = [1,3,2,4,1]
coins = 7
Output = 4
Expected = 4
*/ 