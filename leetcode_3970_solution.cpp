class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto& e : edges) adj[e[0]].push_back({e[1], e[2]});

        const int INF = INT_MAX;
        // dist[u * k + (r - 1)] for run length r in [1, k]
        vector<int> dist((size_t)n * k, INF);

        using T = tuple<int,int,int>; // dist, node, run
        priority_queue<T, vector<T>, greater<T>> pq;

        dist[0] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, r] = pq.top();
            pq.pop();
            if (d > dist[(size_t)u * k + (r - 1)]) continue;
            if (u == n - 1) return d; // first pop of target is optimal

            for (auto& [v, w] : adj[u]) {
                int nr = (labels[v] == labels[u]) ? r + 1 : 1;
                if (nr > k) continue;
                int nd = d + w;
                size_t idx = (size_t)v * k + (nr - 1);
                if (nd < dist[idx]) {
                    dist[idx] = nd;
                    pq.push({nd, v, nr});
                }
            }
        }
        return -1;
    }
};
