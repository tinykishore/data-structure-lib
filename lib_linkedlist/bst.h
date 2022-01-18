// Fully Working, more tests needed

#include <iostream>

typedef struct binary_tree {
    int data;
    struct binary_tree *left;
    struct binary_tree *right;
} BST;

BST *insertBST(BST *root, int data) {
    auto node = new BST();
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;

    if (root == nullptr) {
        return node;
    }

    if (root->data < node->data) {
        root->right = insertBST(root->right, data);
    } else if (root->data > node->data) {
        root->left = insertBST(root->left, data);
    } else {
        std::cout << "Key: " << data << " is already in the tree" << std::endl;
        return root;
    }
    return root;
}

int rightMin(BST *root) {
    BST *temp = root;
    while (root->left != nullptr) {
        temp = temp->left;
    }
    return temp->data;
}

BST *deleteBST(BST *root, int key) {
    if (root == nullptr) {
        printf("Tree is empty\n");
        return nullptr;
    } else if (root->data < key) {
        root->right = deleteBST(root->right, key);
    } else if (root->data > key) {
        root->left = deleteBST(root->left, key);
    } else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        } else if (root->right == nullptr) {
            BST *newNode = root->left;
            delete root;
            return newNode;
        } else if (root->left == nullptr) {
            BST *newNode = root->right;
            delete root;
            return newNode;
        } else {
            int min = rightMin(root->right);
            root->data = min;
            root->right = deleteBST(root->right, min);
        }
    }
    return root;
}

void preorder(BST *node) {
    if (node != nullptr) {
        std::cout << node->data << " -> ";
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(BST *root) {
    if (root != nullptr) {
        inorder(root->left);
        std::cout << root->data << " -> ";
        inorder(root->right);
    }
}

void postorder(BST *node) {
    if (node != nullptr) {
        postorder(node->left);
        postorder(node->right);
        std::cout << node->data << " -> ";
    }
}

int searchBST(BST *root, int data) {
    while (root != nullptr) {
        if (root->data == data)
            return 1;
        else if (data < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return 0;
}