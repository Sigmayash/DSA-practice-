/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
   int kthSmallestRecur(Node* root, int &cnt, int k) {
    if (root == nullptr) return -1;
    
    int left = kthSmallestRecur(root->left, cnt, k);

    if (left != -1) return left;
    
    cnt++;
    
    if (cnt == k) return root->data;
    
    int right = kthSmallestRecur(root->right, cnt, k);
    return right;
}

int kthSmallest(Node* root, int k) {
    int cnt = 0;
    return kthSmallestRecur(root, cnt, k);
}
};