// User function Template for C++

class Solution {
  public:
int order(int n) {
    int t = 0;
    while (n) {
        t++;
        n = n / 10;
    }
    return t;
}

bool armstrongNumber(int n) {
    int x = order(n);
    int temp = n, sum = 0;
    while (temp) {
        int r = temp % 10;
        sum += pow(r, x);  
        temp = temp / 10;
    }
    return (sum == n);
}
};