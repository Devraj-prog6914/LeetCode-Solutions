class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times,
                         int n, int k) {

        vector<vector<pair<int,int>>> graph(n + 1);

        for (auto &t : times)
            graph[t[0]].push_back({t[1], t[2]});

        vector<int> dist(n + 1, INT_MAX);

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node])
                continue;

            for (auto [next, weight] : graph[node]) {
                if (d + weight < dist[next]) {
                    dist[next] = d + weight;
                    pq.push({dist[next], next});
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};