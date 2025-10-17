/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
  public:
    int getHeight(Node* root, int h) {
    if (root == nullptr) return h - 1;
    return max(getHeight(root->left, h + 1), getHeight(root->right, h + 1));
}

void levelOrder(Node* root) {
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    int lastLevel = 0;

    int height = getHeight(root, 0);

    while (!q.empty()) {
        auto [node, lvl] = q.front();
        q.pop();

        if (lvl > lastLevel) {
            cout << "\n";
            lastLevel = lvl;
        }

        if (lvl > height) break;

        if (node->data != -1) cout << node->data << " ";
        else cout << "N ";

        if (node->data == -1) continue;

        if (node->left == nullptr) q.push({new Node(-1), lvl + 1});
        else q.push({node->left, lvl + 1});

        if (node->right == nullptr) q.push({new Node(-1), lvl + 1});
        else q.push({node->right, lvl + 1});
    }
}

void updateTree(Node* root, int& sum) {
    if (root == nullptr) {
        return;
    }

    updateTree(root->right, sum);

    sum += root->data;
    root->data = sum - root->data;

    updateTree(root->left, sum);
}

void transformTree(Node* root) {
  
    int sum = 0; 
    updateTree(root, sum);
}


};