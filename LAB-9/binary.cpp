#include <cstdio>

// Node structure for the character binary tree
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Binary Tree Class
class BinaryTree {
private:
    Node *root;

public:
    BinaryTree();                  
    void insert(int value);       
    void preorder();              
    void inorder();               
    void postorder();             
    bool search(int value);       
    Node* getRoot();               

private:
    Node* insert(Node *node, int value);
    void preorder(Node *node);
    void inorder(Node *node);
    void postorder(Node *node);
    bool search(Node *node, int value);
};

// Constructor
BinaryTree::BinaryTree() : root(nullptr) {}

// Insert a character into the tree
void BinaryTree::insert(int value) {
    root = insert(root, value);
}

// Recursive insertion function
Node* BinaryTree::insert(Node *node, int value) {
    if (node == nullptr) {
        return new Node(value);
    }
    char direction;
    printf("Insert to left (L) or right (R) of %d: ", node->data);
    scanf(" %c", &direction);

    if (direction == 'L' || direction == 'l') {
        node->left = insert(node->left, value);
    } else {
        node->right = insert(node->right, value);
    }
    return node;
}

// Public Preorder traversal
void BinaryTree::preorder() {
    preorder(root);
    printf("\n");
}

// Recursive Preorder traversal
void BinaryTree::preorder(Node *node) {
    if (node == nullptr) return;
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

// Public Inorder traversal
void BinaryTree::inorder() {
    inorder(root);
    printf("\n");
}

// Recursive Inorder traversal
void BinaryTree::inorder(Node *node) {
    if (node == nullptr) return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

// Public Postorder traversal
void BinaryTree::postorder() {
    postorder(root);
    printf("\n");
}

// Recursive Postorder traversal
void BinaryTree::postorder(Node *node) {
    if (node == nullptr) return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

// Search for a character in the tree
bool BinaryTree::search(int value) {
    return search(root, value);
}

// Recursive Search
bool BinaryTree::search(Node *node, int value) {
    if (!node) return false;
    if (node->data == value) return true;
    return search(node->left, value) || search(node->right, value);
}

// Get the root node
Node* BinaryTree::getRoot() {
    return root;
}

// Main function
int main() {
    BinaryTree tree;
    int choice;
    int value;

    while (true) {
        printf("\nMenu:\n");
        printf("1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Exit\n");
        printf("Choose an option (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter integer to insert: ");
                scanf("%d", &value);
                tree.insert(value);
                break;
            case 2:
                printf("Preorder Traversal: ");
                tree.preorder();
                break;
            case 3:
                printf("Inorder Traversal: ");
                tree.inorder();
                break;
            case 4:
                printf("Postorder Traversal: ");
                tree.postorder();
                break;
            case 5:
                printf("Enter integer to search: ");
                scanf("%d", &value);
                if (tree.search(value)) {
                    printf("Integer '%d' found in the tree.\n", value);
                } else {
                    printf("Integer '%d' not found.\n", value);
                }
                break;
            case 6:
                printf("Exiting program... Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}