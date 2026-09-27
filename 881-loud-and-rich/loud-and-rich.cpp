class Solution {
public:
    vector<int> dfs(int person,
                    vector<vector<int>>& graph,
                    vector<int>& quiet,
                    vector<int>& ans) {

        if (ans[person] != -1)
            return {ans[person]};

        int best = person;

        for (int next : graph[person]) {

            dfs(next, graph, quiet, ans);

            if (quiet[ans[next]] < quiet[best])
                best = ans[next];
        }

        ans[person] = best;

        return {best};
    }

    vector<int> loudAndRich(vector<vector<int>>& richer,
                            vector<int>& quiet) {

        int n = quiet.size();

        vector<vector<int>> graph(n);

        for (auto &r : richer) {
            graph[r[1]].push_back(r[0]);
        }

        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            dfs(i, graph, quiet, ans);
        }

        return ans;
    }
};