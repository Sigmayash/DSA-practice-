class Solution {
  public:
    int maxEdgesToAdd(int V, vector<vector<int>> &edges) {
        int existingEdges = edges.size();

        int maxEdges = V * (V - 1) / 2;

        return maxEdges - existingEdges;
    }
};
