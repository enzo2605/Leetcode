/** Creato da Vincenzo Iannucci in data 17/02/2021 
 * Ti viene data la radice di un albero di ricerca binario (BST) e un intero val. 
 * Trova il nodo nel BST che il valore del nodo è uguale a val e restituisci la sottostruttura 
 * radicata con quel nodo. Se tale nodo non esiste, restituire null.
 * **/
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* insertIntoBST(TreeNode* root, int val) {
    // Crea il nodo z
    TreeNode* z = new TreeNode(val);
    TreeNode* y = nullptr;
    TreeNode* x = root;
    // Cerca la posizione corretta dove inserire z
    while (x != nullptr) {
        y = x;
        if (z->val < x->val) {
            x = x->left;
        }
        else x = x->right;
    }
    // Inserisci z a destra o sinstra di y a seconda 
    // del valore di z
    if (y == nullptr) {
        root = z;
    }
    else if (z->val < y->val) {
        y->left = z;
    }
    else y->right = z;
    return root;
}

void inorder(TreeNode* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->val << endl;
        inorder(root->right);
    }
}

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root != nullptr && root->val != val) {
            if (val < root->val) 
                root = root->left;
            else root = root->right;
        }
        return root;
    }
};

int main() {
    vector<int> values = { 4, 2, 7, 1, 3 };
    TreeNode* root = nullptr;
    Solution s;
    for (auto value : values) {
        root = insertIntoBST(root, value);
    }
    TreeNode* el = s.searchBST(root, 2);
    cout << el->val << endl;
    return 0;
}