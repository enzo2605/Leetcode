/** Creato da Vincenzo Iannucci in data 12/02/2021 **/
#include <iostream>
#include "BSTree.hpp"
using namespace std;

class Solution {
public:
    Node<int>* invertTree(Node<int>* root) {
        if (root == nullptr) 
            return root;
        Node<int>* left = root->getLeft();
        Node<int>* right = root->getRight();
        root->setLeft(right);
        root->setRight(left);
        invertTree(right);
        invertTree(left);
        return root;
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

    tree.inorder(s.invertTree(tree.getRoot()));
    return 0;
}