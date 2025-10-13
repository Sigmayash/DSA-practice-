/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> maxSumHelper(Node* root) {
    if (root == NULL) return {0, 0}; 

    vector<int> resLeft = maxSumHelper(root->left);
    vector<int> resRight = maxSumHelper(root->right);

    int include = root->data + resLeft[1] + resRight[1];
    int exclude = max(resLeft[0], resLeft[1]) + 
                  max(resRight[0], resRight[1]);
    return {include, exclude};
}

int getMaxSum(Node* root) {
    vector<int> res = maxSumHelper(root);
    
    return max(res[0], res[1]);
}
};