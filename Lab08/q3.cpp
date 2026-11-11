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

void displayRange(Node* root, int L, int R, int &count) {
    if (root == NULL)
        return;

    if (root->data > L)
        displayRange(root->left, L, R, count);

    if (root->data >= L && root->data <= R) {
        cout << root->data << " ";
        count++;
    }

    if (root->data < R)
        displayRange(root->right, L, R, count);
}

Node* deleteOutsideRange(Node* root, int L, int R) {
    if (root == NULL)
        return NULL;

    root->left = deleteOutsideRange(root->left, L, R);
    root->right = deleteOutsideRange(root->right, L, R);

    if (root->data < L) {
        Node* temp = root->right;
        delete root;
        return temp;
    }

    if (root->data > R) {
        Node* temp = root->left;
        delete root;
        return temp;
    }

    return root;
}

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;

    int ids[] = {50, 25, 75, 10, 30, 60, 90, 20, 40, 70, 80};

    for (int i = 0; i < 11; i++)
        root = insert(root, ids[i]);

    int L = 25, R = 70;
    int count = 0;

    cout << "IDs in range: ";
    displayRange(root, L, R, count);

    cout << "\nCount: " << count;

    root = deleteOutsideRange(root, L, R);

    cout << "\nAfter deleting outside range: ";
    inorder(root);

    return 0;
}

