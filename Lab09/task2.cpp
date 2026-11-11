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

public:
    AVLTree() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void leftRotation() {
        if (root != NULL && root->right != NULL)
            root = rotateLeft(root);
    }

    void display() {
        display(root);
        cout << endl;
    }
};

int main() {
    AVLTree tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    tree.insert(55);

    cout << "AVL Tree after insertion: ";
    tree.display();

    tree.leftRotation();

    cout << "AVL Tree after left rotation: ";
    tree.display();

    return 0;
}

