class Solution {
  public:
   vector<vector<int>> nearest(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
    
    queue<pair<int, int>> q;

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {

            if(grid[i][j] == 1) {
                ans[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    while(!q.empty()) {
        int len = q.size();
        
        for(int i = 0; i<len; i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            vector<vector<int>> directions = 
            {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

            for (int j = 0; j < directions.size(); j++) {
                int dx = directions[j][0];
                int dy = directions[j][1];

                if (x+dx >= 0 && x+dx < n && y+dy >= 0 && 
                    y+dy < m && ans[x+dx][y+dy] == INT_MAX) {
                    ans[x+dx][y+dy] = ans[x][y] + 1;
                    q.push({x+dx, y+dy});
                }
            }
        }
    }

    return ans;
}
};