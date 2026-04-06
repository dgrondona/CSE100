#include <iostream>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

Node* createNode(int key) {

    Node* node = new Node;
    node->key = key;
    node->left = node->right = nullptr;
    return node;

}

Node* insert(Node* root, int key) {

    if (root == nullptr) {
        return createNode(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;

}

void inOrder(Node* root) {

    if (!root) return;

    inOrder(root->left);
    std::cout << root->key << std::endl;

    inOrder(root->right);
}

void preOrder(Node* root) {

    if (!root) return;

    std::cout << root->key << std::endl;

    preOrder(root->left);
    preOrder(root->right);

}

void postOrder(Node* root) {

    if (!root) return;

    postOrder(root->left);
    postOrder(root->right);

    std::cout << root->key << std::endl;

}