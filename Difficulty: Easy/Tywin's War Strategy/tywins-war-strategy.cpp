class Solution {
  public:
   int minSoldiers(vector<int>& arr, int k) {
    int n = arr.size();
    int need = (n + 1) / 2;
    int lucky = 0;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int num : arr) {
        if (num % k == 0) {
            ++lucky;
        } else {
            pq.push(k - (num % k));
        }
    }

    if (lucky >= need) return 0;

    int total = 0;
    int req = need - lucky;

    for (int i = 0; i < req && !pq.empty(); ++i) {
        total += pq.top();
        pq.pop();
    }

    return total;
}
};