/** Creato da Vincenzo Iannucci in data 12/02/2021 **/
#include <iostream>
#include "BSTree.hpp"
using namespace std;

class Solution {
public:
    int rangeSumBST(Node<int>* root, int low, int high) {
        if (root == nullptr) 
            return 0;
        if (root->getKey() < low)
            return rangeSumBST(root->getRight(), low, high);
        if (root->getKey() > high)
            return rangeSumBST(root->getLeft(), low, high);
        return root->getKey() + rangeSumBST(root->getLeft(), low, high) + rangeSumBST(root->getRight(), low, high);
    }
};

int main() {
    BSTree<int> tree;
    Solution s;
    tree.insert_node(10, 1);
    tree.insert_node(5, 2);
    tree.insert_node(15, 3);
    tree.insert_node(3, 4);
    tree.insert_node(7, 5);
    tree.insert_node(18, 6);

    cout << s.rangeSumBST(tree.getRoot(), 7, 15) << endl;
    return 0;
}