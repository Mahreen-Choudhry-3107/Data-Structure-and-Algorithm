class LazySegmentTree {
 public:
  LazySegmentTree(int n, int mod)
      : n(n), mod(mod), lazy(4 * n), sums(4 * n), sq(4 * n) {}

  void updateRange(int l, int r) {
    update(0, 0, n - 1, l, r);
  }

  void propagate(int i, int l, int r) {
    long gap = r - l + 1;
    sq[i] = (sq[i] + 2 * lazy[i] * sums[i] + lazy[i] * lazy[i] * gap) % mod;
    sums[i] = (sums[i] + lazy[i] * gap) % mod;

    if (l < r) {
      lazy[i * 2 + 1] += lazy[i];
      lazy[i * 2 + 2] += lazy[i];
    }
    lazy[i] = 0;
  }

  int getTreeSquaredSums() {
    return sq[0];
  }

 private:
  const int n, mod;
  vector<long> lazy, sums, sq;

  void update(int i, int s, int e, int l, int r) {
    if (lazy[i] > 0) propagate(i, s, e);
    if (e < l || s > r) return;

    if (s >= l && e <= r) {
      lazy[i] = 1;
      propagate(i, s, e);
      return;
    }

    int mid = (s + e) / 2;
    update(i * 2 + 1, s, mid, l, r);
    update(i * 2 + 2, mid + 1, e, l, r);

    sums[i] = (sums[i * 2 + 1] + sums[i * 2 + 2]) % mod;
    sq[i] = (sq[i * 2 + 1] + sq[i * 2 + 2]) % mod;
  }
};

class Solution {
 public:
  int sumCounts(vector<int>& nums) {
    const int mod = 1'000'000'007, n = nums.size();
    int ans = 0;
    unordered_map<int, int> lastSeen;
    LazySegmentTree tree(n, mod);

    for (int r = 0; r < n; ++r) {
      int l = lastSeen.count(nums[r]) ? lastSeen[nums[r]] + 1 : 0;
      tree.updateRange(l, r);
      lastSeen[nums[r]] = r;
      ans = (ans + tree.getTreeSquaredSums()) % mod;
    }

    return ans;
  }
};
