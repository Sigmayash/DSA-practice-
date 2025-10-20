class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
 
    sort(prices.begin(), prices.end());
   
    int n = prices.size();
    int minCost = 0;
    for (int i = 0; i < n; i++) {
        minCost += prices[i];
        n -= k;
    }
  
    int index = -1, maxCost = 0; 
    for (int i = prices.size() - 1; i > index; i--) {
        maxCost += prices[i];
        index += k;
    }

    return {minCost, maxCost};
}

};