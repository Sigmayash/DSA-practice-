/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
int distCandyUtil(Node* root, int& ans) {
  
    if (root == nullptr)
        return 0;

    int l = distCandyUtil(root->left, ans);

    int r = distCandyUtil(root->right, ans);

    ans += abs(l) + abs(r);

    return root->data + l + r - 1;
}


int distCandy(Node* root) {
    int ans = 0;
    distCandyUtil(root, ans);
    return ans;
}

};