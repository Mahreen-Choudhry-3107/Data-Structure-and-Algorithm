class Solution {
public:
    int n, LOG = 16, timer = 0;
    vector<int> bit, tin, tout;
    vector<vector<int>> up;

    void upd(int i, int v) {
        for (; i <= n + 1; i += i & -i) bit[i] ^= v;
    }
    int qry(int i) {
        int r = 0;
        for (; i > 0; i -= i & -i) r ^= bit[i];
        return r;
    }
    void rangeXor(int l, int r, int v) {
        upd(l, v);
        upd(r + 1, v);
    }
    bool isAnc(int a, int b) {
        return tin[a] <= tin[b] && tout[b] <= tout[a];
    }
    int lca(int a, int b) {
        if (isAnc(a, b)) return a;
        if (isAnc(b, a)) return b;
        for (int j = LOG - 1; j >= 0; j--) {
            if (!isAnc(up[j][a], b)) a = up[j][a];
        }
        return up[0][a];
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->n = n;
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        bit.assign(n + 3, 0);
        tin.assign(n, 0);
        tout.assign(n, 0);
        up.assign(LOG, vector<int>(n, 0));

        // iterative DFS
        vector<pair<int, int>> st;
        st.push_back({0, 0});
        up[0][0] = 0;
        tin[0] = ++timer;
        while (!st.empty()) {
            int u = st.back().first;
            int &idx = st.back().second;
            if (idx < (int)adj[u].size()) {
                int v = adj[u][idx++];
                if (v == up[0][u] && u != 0) continue;
                if (v == up[0][u] && u == 0 && false) continue;
                up[0][v] = u;
                tin[v] = ++timer;
                st.push_back({v, 0});
            } else {
                tout[u] = timer;
                st.pop_back();
            }
        }
        for (int j = 1; j < LOG; j++)
            for (int i = 0; i < n; i++)
                up[j][i] = up[j - 1][up[j - 1][i]];

        for (int i = 0; i < n; i++)
            rangeXor(tin[i], tout[i], 1 << (s[i] - 'a'));

        vector<bool> ans;
        for (auto& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;
            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;
                int d = (1 << (s[u] - 'a')) ^ (1 << (c - 'a'));
                if (d) rangeXor(tin[u], tout[u], d);
                s[u] = c;
            } else {
                int u, v;
                ss >> u >> v;
                int l = lca(u, v);
                int mask = qry(tin[u]) ^ qry(tin[v]) ^ (1 << (s[l] - 'a'));
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }
        return ans;
    }
};
