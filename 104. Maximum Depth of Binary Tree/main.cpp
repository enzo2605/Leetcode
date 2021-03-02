/** Creato da Vincenzo Iannucci in data 14/02/2021 
 * Data la radice di un albero binario, restituisci la sua profondità massima. La profondità 
 * massima di un albero binario è il numero di nodi lungo il percorso più lungo dal nodo radice 
 * fino al nodo foglia più lontano.
 * **/
#include <iostream>
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) 
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main() {
    cout << "Hello world!" << endl;
    return 0;
}