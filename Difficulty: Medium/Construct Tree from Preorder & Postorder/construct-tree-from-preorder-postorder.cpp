/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node* constructTreeUtil(vector<int> &pre, vector<int> &post, int &preIndex,
                        int l, int h, int size, unordered_map<int,int> &postMap) {
    if (preIndex >= size || l > h)
        return nullptr;
    Node* root = new Node(pre[preIndex++]);

    if (l == h)
        return root;

 
    int i = postMap[pre[preIndex]];

    if (i <= h) {
        root->left = constructTreeUtil(pre, post, preIndex, l, i, size, postMap);
        root->right = constructTreeUtil(pre, post, preIndex, i + 1, h - 1, size, postMap);
    }

    return root;
}


Node* constructTree(vector<int> &pre, vector<int> &post) {
    int preIndex = 0;
    int size = pre.size();

  
    unordered_map<int,int> postMap;
    for (int i = 0; i < size; i++)
        postMap[post[i]] = i;

    return constructTreeUtil(pre, post, preIndex, 0, size - 1, size, postMap);
}

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
};