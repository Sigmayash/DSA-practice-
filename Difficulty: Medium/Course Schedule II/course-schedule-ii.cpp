class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
    
   
    vector<vector<int>> adj(n);
    vector<int> inDegree(n, 0);

    for (auto& pre : prerequisites) {
        int dest = pre[0];
        int src = pre[1];
        adj[src].push_back(dest);
        inDegree[dest]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> order;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        order.push_back(current);

        for (int neighbor : adj[current]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    if (order.size() == n) {
        return order;
    } 
    
    return {}; 
    
}

};