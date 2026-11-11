#include <iostream>
using namespace std;

class AVLTree {
    struct Node {
        int data;
        Node* left;
        Node* right;
    };

    Node* root;

    int height(Node* node) {
        if (node == NULL)
            return 0;

        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        if (leftHeight > rightHeight)
            return leftHeight + 1;

        return rightHeight + 1;
    }

    int balanceFactor(Node* node) {
        if (node == NULL)
            return 0;

        return height(node->left) - height(node->right);
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* t2 = y->left;

        y->left = x;
        x->right = t2;

        return y;
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* t2 = x->right;

        x->right = y;
        y->left = t2;

        return x;
    }

    Node* insert(Node* node, int value) {
        if (node == NULL) {
            Node* newNode = new Node;
            newNode->data = value;
            newNode->left = NULL;
            newNode->right = NULL;
            return newNode;
        }

        if (value < node->data)
            node->left = insert(node->left, value);

        else if (value > node->data)
            node->right = insert(node->right, value);

        else
            return node;

        int bf = balanceFactor(node);

        if (bf > 1 && value < node->left->data)
            return rotateRight(node);

        if (bf < -1 && value > node->right->data)
            return rotateLeft(node);

        if (bf > 1 && value > node->left->data) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (bf < -1 && value < node->right->data) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    void display(Node* node) {
        if (node == NULL)
            return;

        cout << node->data << " ";
        display(node->left);
        display(node->right);
    }

    void showBalance(Node* node) {
        if (node == NULL)
            return;

        showBalance(node->left);

        cout << "Node " << node->data
             << " : " << balanceFactor(node) << endl;

        showBalance(node->right);
    }

public:
    AVLTree() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void display() {
        display(root);
        cout << endl;
    }

    void showBalance() {
        showBalance(root);
    }

    int height() {
        return height(root) - 1;
    }
};

int main() {
    AVLTree tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);

    tree.insert(12); //tree is still balanced after this insertion hence no rotation needed

    cout << "AVL Tree: ";
    tree.display();

    cout << "\nBalance Factors:\n";
    tree.showBalance();

    cout << "\nHeight of Tree: " << tree.height();

    return 0;
}

