class Solution {
public:
    vector<vector<int>> g;
    vector<int> vals;
    int K;
    int ans = 0;

    int dfs(int u, int parent) {
        long long sum = vals[u];

        for (int v : g[u]) {
            if (v == parent) continue;
            int child = dfs(v, u);

            if (child == 0) {
                ans++;              // child subtree forms a component
            } else {
                sum += child;       // accumulate upward
            }
        }
        return sum % K;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        g.assign(n, {});
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        vals = values;
        K = k;

        int rootSum = dfs(0, -1);
        if (rootSum == 0) ans++;      // final component

        return ans;
    }
};
