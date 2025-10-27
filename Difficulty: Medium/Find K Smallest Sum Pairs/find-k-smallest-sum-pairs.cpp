class Solution {
  public:
   vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
    vector<vector<int>> ans;

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    set<pair<int, int>> my_set;

    pq.push({arr1[0] + arr2[0], 0, 0});
    my_set.insert({0, 0});

    while (!pq.empty() && ans.size() < k) {
        auto temp = pq.top();
        pq.pop();
        int i = temp[1];
        int j = temp[2];
        ans.push_back({arr1[i], arr2[j]});

        if (i + 1 < arr1.size() && !my_set.count({i + 1, j})) {
            pq.push({arr1[i + 1] + arr2[j], i + 1, j});
            my_set.insert({i + 1, j});
        }
        if (j + 1 < arr2.size() && !my_set.count({i, j + 1})) {
            pq.push({arr1[i] + arr2[j + 1], i, j + 1});
            my_set.insert({i, j + 1});
        }
    }

    return ans;
}

};
