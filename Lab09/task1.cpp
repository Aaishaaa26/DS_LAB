#include <iostream>
using namespace std;

struct Node {
    int rollNo;
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

Node* insert(Node* root, int value) {
    if (root == NULL) {
        Node* newNode = new Node;
        newNode->rollNo = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (value < root->rollNo)
        root->left = insert(root->left, value);

    else if (value > root->rollNo)
        root->right = insert(root->right, value);

    else
        return root;

    int bf = balanceFactor(root);

    if (bf > 1 && value < root->left->rollNo)
        return rotateRight(root);

    if (bf < -1 && value > root->right->rollNo)
        return rotateLeft(root);

    if (bf > 1 && value > root->left->rollNo) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (bf < -1 && value < root->right->rollNo) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void display(Node* root) {
    if (root == NULL)
        return;

    cout << root->rollNo << " ";
    display(root->left);
    display(root->right);
}

int main() {
    Node* root = NULL;

    root = insert(root, 10); // 20 LC
    root = insert(root, 20); //root
    root = insert(root, 30); //40 LC
    root = insert(root, 40); //20 RC
    root = insert(root, 50); //40 RC

    root = insert(root, 15); // becomes 10z RC, tree already balaned

    cout << "AVL Tree: ";
    display(root);

    cout << endl;

    cout << "Height: " << height(root) - 1; //no rotation needed since bf are in range

    return 0;
}
