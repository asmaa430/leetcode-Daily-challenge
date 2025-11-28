class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
vector<int>& values, int k) {
        vector<vector<int>> graph(n);
        
        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        int answer = 0;

        function<long long(int,int)> dfs = [&](int node, int parent) {
            long long sum = values[node];

            for (int child : graph[node]) {
                if (child == parent) continue;
                sum += dfs(child, node);
            }

            if (sum % k == 0) {
                answer++;
                return 0LL;  
            }

            return sum;
        };

        dfs(0, -1);
        return answer;
    }
};