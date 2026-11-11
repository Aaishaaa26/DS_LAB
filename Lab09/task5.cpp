#include <iostream>
using namespace std;

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

bool isBalanced(Node* root) {
    if (root == NULL)
        return true;

    int bf = height(root->left) - height(root->right);

    if (bf > 1 || bf < -1)
        return false;

    return isBalanced(root->left) && isBalanced(root->right);
}

void inorder(Node* root, Node* arr[], int &index) {
    if (root == NULL)
        return;

    inorder(root->left, arr, index);

    arr[index] = root;
    index++;

    inorder(root->right, arr, index);
}

Node* buildBalanced(Node* arr[], int start, int end) {
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;

    Node* root = arr[mid];

    root->left = buildBalanced(arr, start, mid - 1);
    root->right = buildBalanced(arr, mid + 1, end);

    return root;
}

Node* convertToBalanced(Node* root) {
    Node* arr[100];
    int index = 0;

    inorder(root, arr, index);

    return buildBalanced(arr, 0, index - 1);
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

    cout << "Tree A Balanced: ";
    cout << (isBalanced(rootA) ? "Yes" : "No") << endl;

    cout << "Tree B Balanced: ";
    cout << (isBalanced(rootB) ? "Yes" : "No") << endl;

    rootA = convertToBalanced(rootA);
    rootB = convertToBalanced(rootB);

    cout << "\nBalanced Tree A: ";
    display(rootA);

    cout << "\nBalanced Tree B: ";
    display(rootB);

    cout << "\nHeight of Tree A: " << height(rootA) - 1;
    cout << "\nHeight of Tree B: " << height(rootB) - 1;

}

