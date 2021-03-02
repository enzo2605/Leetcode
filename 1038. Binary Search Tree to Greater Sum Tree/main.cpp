/** Creato da Vincenzo Iannucci in data 12/02/2021 
 * Data la radice di un albero di ricerca binario (BST), convertilo in un albero maggiore in modo 
 * tale che ogni chiave del BST originale venga modificata nella chiave originale più la somma di 
 * tutte le chiavi maggiori della chiave originale in BST.
 * **/
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        stack<TreeNode*> ps;
        TreeNode* node = root;
        auto sum = 0;
        while (root != nullptr || !ps.empty()) {
            if (root != nullptr) {
                ps.push(root);
                root = root->right;
            }
            else {
                root = ps.top();
                ps.pop();
                sum += root->val;
                root->val = sum;
                root = root->left;
            }
        }
        return node;
    }
};

int main() {
    
    return 0;
}