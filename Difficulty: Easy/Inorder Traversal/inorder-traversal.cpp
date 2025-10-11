/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> inOrder(Node* root) {
    vector<int> res;
    inOrder(root, res); 
    return res;
}

void inOrder(Node* node, vector<int>& res) {
    if (node == nullptr)
        return;
    inOrder(node->left, res);

    res.push_back(node->data);

    inOrder(node->right, res);
}
};