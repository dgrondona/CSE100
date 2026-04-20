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

// Find the min
Node* findMin(Node* root) {

    while (root->left != nullptr) {
        root = root->left;
    }

    return root;
}

// Delete node
Node* deleteNode(Node* root, int key) {

    if (!root) return nullptr;

    if (key < root->key) {

        root->left = deleteNode(root->left, key);

    } else if (key > root->key) {

        root->right = deleteNode(root->right, key);

    } else {

        if (!root->left && !root->right) {

            delete root;
            return nullptr;

        } else if (!root->left) {

            Node* temp = root->right;
            delete root;
            return temp;

        } else if (!root->right) {

            Node* temp = root->left;
            delete root;
            return temp;

        }

        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);

    }

    return root;

}

int main(int argc, char **argv) {

    Node* root = nullptr;
    string input;

    // Handle input commands
    while (cin >> input) {

        if (input == "e") {

            break;

        } else if (input[0] == 'i') {

            int key = stoi(input.substr(1));
            root = insert(root, key);

        } else if (input[0] == 'd') {

            int key = stoi(input.substr(1));
            root = deleteNode(root, key);

        } else if (input == "oin") {

            inOrder(root);

        } else if (input == "opre") {

            preOrder(root);

        } else if (input == "opost") {

            postOrder(root);

        }

    }

}