/** Creato da Vincenzo Iannucci in data 17/02/2021 
 * Ti viene fornito il nodo radice di un albero di ricerca binario (BST) e un valore da inserire 
 * nell'albero. Restituisci il nodo radice del BST dopo l'inserimento. È garantito che il nuovo 
 * valore non esiste nella BST originale. Si noti che possono esistere più modi validi per l'inserimento, 
 * purché l'albero rimanga un BST dopo l'inserimento. Puoi restituire uno qualsiasi di loro.
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

void inorder(TreeNode* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->val << endl;
        inorder(root->right);
    }
}

class Solution {
public:
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
};

int main() {
    Solution s;
    vector<int> values = { 4, 2, 7, 1, 3, 5 };
    TreeNode* root = nullptr;
    for (auto value : values) {
        root = s.insertIntoBST(root, value);
    }
    inorder(root);
    return 0;
}