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


}
};
