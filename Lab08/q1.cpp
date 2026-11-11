#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);

    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void preorder(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int countOneChild(Node* root) {
    if (root == NULL)
        return 0;

    if ((root->left == NULL && root->right != NULL) ||
        (root->left != NULL && root->right == NULL))
        return 1 + countOneChild(root->left) + countOneChild(root->right);

    return countOneChild(root->left) + countOneChild(root->right);
}

int countTwoChildren(Node* root) {
    if (root == NULL)
        return 0;

    if (root->left != NULL && root->right != NULL)
        return 1 + countTwoChildren(root->left) + countTwoChildren(root->right);

    return countTwoChildren(root->left) + countTwoChildren(root->right);
}

int height(Node* root) {
    if (root == NULL)
        return -1;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (leftHeight > rightHeight)
        return leftHeight + 1;

    return rightHeight + 1;
}

int main() {
    Node* root = NULL;

    int scores[] = {45, 25, 65, 15, 35, 55, 75, 30};

    for (int i = 0; i < 8; i++) {
        root = insert(root, scores[i]);
    }

    cout << "Preorder: ";
    preorder(root);

    cout << "\nInorder: ";
    inorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    cout << "\nNodes with one child: " << countOneChild(root);

    cout << "\nNodes with two children: " << countTwoChildren(root);

    cout << "\nHeight (edges): " << height(root);

}

