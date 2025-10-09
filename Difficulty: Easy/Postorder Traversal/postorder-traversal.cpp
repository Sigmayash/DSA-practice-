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
    vector<int> postOrder(Node *root) {
    vector<int> res;
    Node *current = root;

    while (current != NULL) {

        if (current->right == NULL) {
            res.push_back(current->data);
            current = current->left;
        }
        else {
            Node *predecessor = current->right;
            while (predecessor->left != NULL && predecessor->left != current) {
                predecessor = predecessor->left;
            }

            if (predecessor->left == NULL) {
                res.push_back(current->data);
                predecessor->left = current;
                current = current->right;
            }
            
            else {
                predecessor->left = NULL;
                current = current->left;
            }
        }
    }
    
    reverse(res.begin(), res.end());
    return res;
}
};