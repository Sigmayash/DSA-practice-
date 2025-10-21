class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {

    unordered_map<int, int> mp;
    for (int val: arr)
        mp[val]++;

    priority_queue<pair<int, int>, 
    vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    for (pair<int, int> entry : mp) {
     
        pq.push({entry.second, entry.first});
     
        if (pq.size() > k)
            pq.pop();
    }

    vector<int> res(k);

    for (int i = k-1; i >= 0; i--) {
        res[i] = pq.top().second;
        pq.pop();
    }
    
    return res;
}
};
