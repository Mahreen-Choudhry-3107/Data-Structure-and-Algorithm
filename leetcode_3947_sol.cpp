class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<long long> cnt(n + 1, 0), M(n + 1, 0);
        for (auto& it : items) cnt[it[0]]++;
        for (int f = 1; f <= n; f++)
            for (int m = f; m <= n; m += f)
                M[f] += cnt[m];

        // (price, d)
        vector<pair<long long, long long>> v;
        v.reserve(n);
        for (auto& it : items)
            v.push_back({it[1], M[it[0]] - 1});
        sort(v.begin(), v.end());

        long long pm = v[0].first;
        long long R = budget;
        long long total = 0;

        for (auto& [p, d] : v) {
            if (p > 2 * pm) break;
            long long t = min(d, R / p);
            R -= t * p;
            total += 2 * t;
            if (t < d) break;   // budget limited; no point continuing
        }
        total += R / pm;
        return (int)total;
    }
};
