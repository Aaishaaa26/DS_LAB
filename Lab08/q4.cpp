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

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;

    return root->data;
}

int findMax(Node* root) {
    while (root->right != NULL)
        root = root->right;

    return root->data;
}

void displayGreater(Node* root, double threshold) {
    if (root == NULL)
        return;

    displayGreater(root->left, threshold);

    if (root->data > threshold)
        cout << root->data << " ";

    displayGreater(root->right, threshold);
}

int countTwoChildren(Node* root) {
    if (root == NULL)
        return 0;

    if (root->left != NULL && root->right != NULL)
        return 1 + countTwoChildren(root->left) + countTwoChildren(root->right);

    return countTwoChildren(root->left) + countTwoChildren(root->right);
}

int countOneChild(Node* root) {
    if (root == NULL)
        return 0;

    if ((root->left == NULL && root->right != NULL) ||
        (root->left != NULL && root->right == NULL))
        return 1 + countOneChild(root->left) + countOneChild(root->right);

    return countOneChild(root->left) + countOneChild(root->right);
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

void printLongestPath(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";

    if (root->left == NULL && root->right == NULL)
        return;

    if (height(root->left) > height(root->right))
        printLongestPath(root->left);
    else
        printLongestPath(root->right);
}

bool isSkewed(Node* root) {
    if (root == NULL)
        return true;

    if (root->left != NULL && root->right != NULL)
        return false;

    return isSkewed(root->left) && isSkewed(root->right);
}

Node* findSuccessor(Node* root) {
    while (root->left != NULL)
        root = root->left;

    return root;
}

Node* deleteNode(Node* root, int value) {
    if (root == NULL)
        return NULL;

    if (value < root->data)
        root->left = deleteNode(root->left, value);

    else if (value > root->data)
        root->right = deleteNode(root->right, value);

    else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        else {
            Node* temp = findSuccessor(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

Node* deleteOneChild(Node* root, int &deleted) {
    if (root == NULL)
        return NULL;

    int value = root->data;

    bool oneChild = (root->left == NULL && root->right != NULL) ||
                    (root->left != NULL && root->right == NULL);

    root->left = deleteOneChild(root->left, deleted);
    root->right = deleteOneChild(root->right, deleted);

    if (oneChild) {
        root = deleteNode(root, value);
        deleted++;
    }

    return root;
}

void kthSmallest(Node* root, int k, int &count, int &answer) {
    if (root == NULL || count >= k)
        return;

    kthSmallest(root->left, k, count, answer);

    if (count < k) {
        count++;

        if (count == k)
            answer = root->data;
    }

    kthSmallest(root->right, k, count, answer);
}

int main() {
    Node* root = NULL;

    int values[] = {45, 25, 65, 15, 35, 55, 75,
                    10, 30, 40, 60, 80, 32, 33};

    for (int i = 0; i < 14; i++)
        root = insert(root, values[i]);

    cout << "Original inorder: ";
    inorder(root);

    int min = findMin(root);
    int max = findMax(root);

    double threshold = (min + max) / 2.0;

    cout << "\nMinimum: " << min;
    cout << "\nMaximum: " << max;
    cout << "\nThreshold: " << threshold;

    cout << "\nMarks greater than threshold: ";
    displayGreater(root, threshold);

    cout << "\nNodes with two children: " << countTwoChildren(root);

    cout << "\nLongest root-to-leaf path: ";
    printLongestPath(root);

    cout << "\nHeight (edges): " << height(root);

    cout << "\nIs BST skewed? ";
    if (isSkewed(root))
        cout << "Yes";
    else
        cout << "No";

    int deleted = 0;

    root = deleteOneChild(root, deleted);

    cout << "\nNodes deleted: " << deleted;

    cout << "\nFinal inorder: ";
    inorder(root);

    int k = 4;
    int count = 0;
    int answer = -1;

    kthSmallest(root, k, count, answer);

    if (k > 0 && count == k)
        cout << "\n" << k << "th smallest mark: " << answer;
    else
        cout << "\nInvalid k";

    return 0;
}

