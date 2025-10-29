class Solution {
  public:
    void dfs(int node, int dist, vector<vector<int>> &adj,
             vector<bool> &visited, int &maxDist, int &farthestNode) {
        
        visited[node] = true;
        
        if (dist > maxDist) {
            maxDist = dist;
            farthestNode = node;
        }
        
        for (int next : adj[node]) {
            if (!visited[next]) {
                dfs(next, dist + 1, adj, visited, maxDist, farthestNode);
            }
        }
    }

    int diameter(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(V, false);
        int maxDist = -1, farthestNode = 0;
        dfs(0, 0, adj, visited, maxDist, farthestNode);

        fill(visited.begin(), visited.end(), false);
        maxDist = -1;
        dfs(farthestNode, 0, adj, visited, maxDist, farthestNode);

        return maxDist;
    }
};
