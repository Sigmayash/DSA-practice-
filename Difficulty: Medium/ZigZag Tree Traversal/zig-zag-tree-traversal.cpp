/*
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
    vector<int> res;
    if (!root) return res;

    deque<Node*> dq;
    dq.push_back(root);

    bool reverse = false;

    while (!dq.empty()) {
        int n = dq.size();

        while (n--) {
            
            if (reverse) {
                Node* curr = dq.back();
                dq.pop_back();
                res.push_back(curr->data);

                if (curr->right) dq.push_front(curr->right);
                if (curr->left)  dq.push_front(curr->left);
            }
        
            else {
                Node* curr = dq.front();
                dq.pop_front();
                res.push_back(curr->data);

                if (curr->left)  dq.push_back(curr->left);
                if (curr->right) dq.push_back(curr->right);
            }
        }

        reverse = !reverse;
    }

    return res;
}

};