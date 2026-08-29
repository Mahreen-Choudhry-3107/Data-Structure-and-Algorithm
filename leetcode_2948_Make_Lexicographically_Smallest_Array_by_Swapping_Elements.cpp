class Solution {
public:
    vector<int> parent, rnk;

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (rnk[x] < rnk[y]) swap(x, y);
        parent[y] = x;
        if (rnk[x] == rnk[y]) rnk[x]++;
    }

    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        parent.resize(n);
        rnk.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);

        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });

        // Union consecutive elements (in sorted-by-value order) that are within limit
        for (int i = 1; i < n; i++)
            if (nums[idx[i]] - nums[idx[i - 1]] <= limit)
                unite(idx[i], idx[i - 1]);

        // Group original indices by their DSU root
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++)
            groups[find(i)].push_back(i);

        vector<int> ans(n);
        for (auto& [root, indices] : groups) {
            vector<int> sortedIdx = indices;
            sort(sortedIdx.begin(), sortedIdx.end());          // positions in array
            vector<int> vals;
            for (int i : sortedIdx) vals.push_back(nums[i]);
            sort(vals.begin(), vals.end());                    // values to place
            for (int i = 0; i < sortedIdx.size(); i++)
                ans[sortedIdx[i]] = vals[i];
        }

        return ans;
    }
};
