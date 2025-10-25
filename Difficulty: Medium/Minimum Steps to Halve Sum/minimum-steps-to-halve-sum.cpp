class Solution {
  public:
    int minOperations(vector<int>& arr) {
    double sum = 0;

    for (int x : arr) sum += x;
    double target = sum / 2;
    priority_queue<double> pq;
    for (int x : arr) pq.push(x);

    int ops = 0;

    while (sum > target) {
        double x = pq.top(); pq.pop();
        double h = x / 2;
        sum -= h;
        pq.push(h);
        ops++;
    }
    return ops;
}
};