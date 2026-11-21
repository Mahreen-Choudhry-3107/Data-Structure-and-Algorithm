class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++) children[parent[i]].push_back(i);

        vector<int> newParent(parent);
        vector<int> order;
        order.reserve(n);

        // last[c] = deepest node with char c on the current path
        vector<int> last(26, -1);
        // stack entries: {node, state}; state 0 = enter, 1 = exit
        // on exit we need to restore last[c], so store the previous value
        vector<int> prevVal(n, -1);
        vector<pair<int,int>> st;
        st.push_back({0, 0});

        while (!st.empty()) {
            auto [x, state] = st.back();
            st.pop_back();
            int c = s[x] - 'a';
            if (state == 0) {
                order.push_back(x);
                if (x != 0 && last[c] != -1) newParent[x] = last[c];
                prevVal[x] = last[c];
                last[c] = x;
                st.push_back({x, 1});
                for (int ch : children[x]) st.push_back({ch, 0});
            } else {
                last[c] = prevVal[x];
            }
        }

        vector<int> ans(n, 1);
        for (int i = n - 1; i > 0; i--) {
            int x = order[i];
            ans[newParent[x]] += ans[x];
        }
        return ans;
    }
};
