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