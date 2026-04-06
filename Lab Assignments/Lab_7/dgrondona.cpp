#include <iostream>

using namespace std;

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

Node* insert(Node* root, int key) {

    if (root == NULL) {
        Node* newNode = (Node*) malloc(sizeof(Node));
        newNode->key = key;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;

}