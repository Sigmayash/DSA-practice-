class Solution {
  public:
    bool canAttend(vector<vector<int>>& meetings) {
    sort(meetings.begin(), meetings.end());

    for (int i = 1; i < meetings.size(); i++) {
        if (meetings[i][0] < meetings[i-1][1]) {
            return false;
        }
    }
    return true;
}
};