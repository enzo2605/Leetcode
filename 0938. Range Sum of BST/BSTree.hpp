#include <iostream>
#include "Node.hpp"

template <class T>
class BSTree {
private:
    Node<T>* root;
    void transplant(Node<T>* u, Node<T>* v);
public:
    BSTree(){ root = nullptr; };
    ~BSTree(){};
    Node<T>* getRoot() { return root; }
    Node<T>* search(int key, T data);
    Node<T>* minimum(Node<T>* x);
    Node<T>* maximum(Node<T>* x);
    Node<T>* successor(Node<T>* x);
    Node<T>* predecessor(Node<T>* x);
    void insert_node(int key, T data);
    void delete_node(int key, T data);
    void inorder(Node<T>* x);
    void preorder(Node<T>* x);
    void postorder(Node<T>* x);
};

template<class T>
void BSTree<T>::transplant(Node<T>* u, Node<T>* v) {
    if (u->getParent() == nullptr) {
        root = v;
    }
    else if (u->getParent()->getLeft() == u) {
        u->getParent()->setLeft(v);
    }
    else {
        u->getParent()->setRight(v);
    }
    if (v != nullptr) {
        v->setParent(u->getParent());
    }
}

template<class T>
Node<T>* BSTree<T>::search(int key, T data) {
    Node<T>* x = root;
    while (x != nullptr && key != x->getKey() && x->getData() != data) {
        if (key < x->getKey()) {
            x = x->getLeft();
        }
        else x = x->getRight();
    }
    return x;
}

template<class T>
Node<T>* BSTree<T>::minimum(Node<T>* x) {
    while (x->getLeft() != nullptr) {
        x = x->getLeft();
    }
    return x;
}

template<class T>
Node<T>* BSTree<T>::maximum(Node<T>* x) {
    while (x->getRight() != nullptr) {
        x = x->getLeft();
    }
    return x;
}

template<class T>
Node<T>* BSTree<T>::successor(Node<T>* x) {
    // Se il nodo ha il sottoalbero sinistro
    if (x->getRight() != nullptr) {
        return minimum(x->getRight());
    }
    Node<T>* y = x->getParent();
    while (y != nullptr && y->getRight() == x) {
        x = y;
        y = y->getParent();
    }
    return y;
}

template<class T>
Node<T>* BSTree<T>::predecessor(Node<T>* x) {
    // Se il nodo ha il sottoalbero sinistro
    if (x->getLeft() != nullptr) {
        return maximum(x->getLeft());
    }
    Node<T>* y = x->getParent();
    while (y != nullptr && y->getLeft() == x) {
        x = y;
        y = y->getParent();
    }
    return y;
}

template<class T>
void BSTree<T>::insert_node(int key, T data) {
    Node<T>* z = new Node<T>(key, data);
    Node<T>* y = nullptr;
    Node<T>* x = root;
    // Fintanto che non trova il posto corretto dove inserire z
    while (x != nullptr) {
        y = x;
        if (z->getKey() <= x->getKey()) {
            x = x->getLeft();
        }
        else x = x->getRight();
    }
    z->setParent(y);
    if (y == nullptr) {
        root = z;
    }
    else if(y->getKey() >= z->getKey()) {
        y->setLeft(z);
    }
    else {
        y->setRight(z);
    }
}

template<class T>
void BSTree<T>::delete_node(int key, T data) {
    Node<T>* z = search(key, data);
    // Caso 1: figlio sinistro nullptr
    if (z->getLeft() == nullptr) {
        transplant(z, z->getRight());
    }
    // Caso 2: figlio destro nullptr
    else if (z->getRight() == nullptr) {
        transplant(z, z->getLeft());
    }
    // Caso 3: figlio sinistro e destro diversi da nullptr
    else {
        Node<T>* y = minimum(z->getRight());
        // Caso 3a: il successore di z NON è figlio diretto
        if (y->getParent() != z) {
            transplant(y, y->getRight());
            y->setRight(z->getRight());
            y->getRight()->setParent(y);
        }
        // Caso 3b: il successore di z è figlio diretto
        transplant(z, y);
        y->setLeft(z->getLeft());
        y->getLeft()->setParent(y);
    }
}

template<class T>
void BSTree<T>::inorder(Node<T>* x) {
    if (x != nullptr) {
        inorder(x->getLeft());
        std::cout << " " << x->getKey();
        inorder(x->getRight());
    }
}

template<class T>
void BSTree<T>::preorder(Node<T>* x) {
    if (x != nullptr) {
        std::cout << " " << x->getKey();
        inorder(x->getLeft());
        inorder(x->getRight());
    }
}

template<class T>
void BSTree<T>::postorder(Node<T>* x) {
    if (x != nullptr) {
        inorder(x->getLeft());
        inorder(x->getRight());
        std::cout << " " << x->getKey();
    }
}