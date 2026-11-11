#include <iostream>
using namespace std;
//An AVL tree is used to keep a BST balanced so that its height does not become too large
//It provides efficient searching, insertion, and deletion in Ologn time

struct Node {
    int data;
    Node* left;
    Node* right;
};

int height(Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (leftHeight > rightHeight)
        return leftHeight + 1;

    return rightHeight + 1;
}

int balanceFactor(Node* root) {
    if (root == NULL)
        return 0;

    return height(root->left) - height(root->right);
}

Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* t2 = x->right;

    x->right = y;
    y->left = t2;

    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* t2 = y->left;

    y->left = x;
    x->right = t2;

    return y;
}

Node* convertToAVL(Node* root) {
    if (root == NULL)
        return NULL;

    root->left = convertToAVL(root->left);
    root->right = convertToAVL(root->right);

    int bf = balanceFactor(root);

    if (bf > 1) {
        if (balanceFactor(root->left) < 0)
            root->left = rotateLeft(root->left);

        return rotateRight(root);
    }

    if (bf < -1) {
        if (balanceFactor(root->right) > 0)
            root->right = rotateRight(root->right);

        return rotateLeft(root);
    }

    return root;
}

void display(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    display(root->left);
    display(root->right);
}

int main() {
    Node* rootA = new Node{10, NULL, NULL};
    rootA->left = new Node{6, NULL, NULL};
    rootA->left->left = new Node{4, NULL, NULL};
    rootA->left->right = new Node{8, NULL, NULL};

    Node* rootB = new Node{10, NULL, NULL};
    rootB->right = new Node{16, NULL, NULL};
    rootB->right->left = new Node{12, NULL, NULL};
    rootB->right->right = new Node{18, NULL, NULL};

    rootA = convertToAVL(rootA);
    rootB = convertToAVL(rootB);

    cout << "AVL Tree A: ";
    display(rootA);
//6 is returned since now its the root after right rotation
    cout << endl;

    cout << "AVL Tree B: ";
    display(rootB);
//16 is returned since now its the root after left rortaion
    cout << endl;
//why? we return the new root since the original one isnt at the top anymore which gets connected to the caller root.

}
