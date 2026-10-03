class Solution {
 public:
  int longestValidParentheses(string str) {
    const string temp = ")" + str;
    vector<int> lengths(temp.length());

    for (int i = 1; i < temp.length(); ++i)
      if (temp[i] == ')' && temp[i - lengths[i - 1] - 1] == '(')
        lengths[i] = lengths[i - 1] + lengths[i - lengths[i - 1] - 2] + 2;

    return ranges::max(lengths);
  }
};
