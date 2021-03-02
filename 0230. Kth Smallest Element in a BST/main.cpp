/** Creato da Vincenzo Iannucci in data 16/02/2021 
 * Data la radice di un albero di ricerca binario e un intero k, restituisce l'elemento più
 * piccolo k-esimo (1-indicizzato) dell'albero.
 * **/
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorder(TreeNode *root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << " " << root->val;
        inorder(root->right);
    }
}

void insert_node(TreeNode *root, TreeNode *z) {
    TreeNode *y = nullptr;
    TreeNode *x = root;
    while (x != nullptr) {
        y = x;
        if (z->val < x->val) {
            x = x->left;
        }
        else x = x->right;
    }
    z->parent = y;
    if (y == nullptr) {
        root = z;
    }
    else if (z->val < y->val) {
        y->left = z;
    }
    else y->right = z;
}

void printVector(vector<int> A) {
    for (auto x : A) {
        cout << " " << x;
    } 
    cout << endl;
}

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& A) {
        if (root != nullptr) {
            inorder(root->left, A);
            A.push_back(root->val);
            inorder(root->right, A);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> A;
        inorder(root, A);
        return A.at(k - 1);
    }
};

int main() {
    vector<int> values = { 3, 1, 2, 4 };
    TreeNode *root = new TreeNode(3);
    TreeNode *node = nullptr;
    Solution s;
    for (auto i = 1; i < values.size(); i++) {
        node = new TreeNode(values[i]);
        insert_node(root, node);
    }
    cout << s.kthSmallest(root, 2) << endl;
    return 0;
}