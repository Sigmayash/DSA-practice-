class Solution {
  public:
    int findMoves(vector<int>& chairs, vector<int>& passengers) {
    sort(chairs.begin(),chairs.end());
    sort(passengers.begin(),passengers.end());
    
        int n = chairs.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += abs(chairs[i] - passengers[i]); 
        }
        
        return ans;
    }
};