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
        auto top = q.front(); q.pop();
        Node* node = top.first;
        int lvl = top.second;

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

Node* removekeys(Node* root, int l, int r) {

    if (root == nullptr) return nullptr;
    Node* left = removekeys(root->left, l, r);
    Node* right = removekeys(root->right, l ,r);
   
    if (root->data>=l && root->data<=r) {
        root->left = left;
        root->right = right;
        
        return root;
    }
    
    else if (root->data<l) {
        return right;
    }
    
    else 
        return left;
}

};