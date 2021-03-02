template <class T>
class Node {
private:
    Node<T>* parent;
    Node<T>* left;
    Node<T>* right;
    int key;
    T data;
public:
    Node(int k, T d) : key(k), data(d) {
        parent = nullptr;
        left = nullptr;
        right = nullptr;
    };
    Node(){};
    ~Node(){};
    void setParent(Node<T>* p) { parent = p; }
    Node<T>* getParent() { return parent; }
    void setLeft(Node<T>* l) { left = l; }
    Node<T>* getLeft() { return left; }
    void setRight(Node<T>* r) { right = r; }
    Node<T>* getRight() { return right; }
    void setKey(int k) { key = k; }
    int getKey() { return key; }
    T getData() { return data; }
};