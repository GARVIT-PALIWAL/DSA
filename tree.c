#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SPACE 10

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert node into BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Search node
bool search(struct Node* root, int key) {
    if (root == NULL)
        return false;
    if (root->data == key)
        return true;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Find min value node (used in delete)
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Delete node from BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Traversals
void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(struct Node* root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Count total nodes
int countNodes(struct Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Count leaf nodes
int countLeaves(struct Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

// Height of the tree
int height(struct Node* root) {
    if (!root) return 0;
    int l = height(root->left);
    int r = height(root->right);
    return (l > r ? l : r) + 1;
}

// Mirror of the tree
void mirror(struct Node* root) {
    if (root) {
        mirror(root->left);
        mirror(root->right);
        struct Node* temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

// Lowest Common Ancestor
struct Node* lca(struct Node* root, int n1, int n2) {
    if (!root) return NULL;

    if (root->data > n1 && root->data > n2)
        return lca(root->left, n1, n2);
    if (root->data < n1 && root->data < n2)
        return lca(root->right, n1, n2);

    return root;
}

// Rotated tree print
void printTree(struct Node* root, int space) {
    if (root == NULL) return;

    space += SPACE;
    printTree(root->right, space);
    printf("\n");
    for (int i = SPACE; i < space; i++) printf(" ");
    printf("%d\n", root->data);
    printTree(root->left, space);
}

// ----------- Main Program -----------

int main() {
    struct Node* root = NULL;
    int choice, val, n1, n2;

    while (1) {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Inorder\n5. Preorder\n6. Postorder\n");
        printf("7. Count Nodes\n8. Count Leaf Nodes\n9. Height\n10. Mirror Tree\n");
        printf("11. Lowest Common Ancestor\n12. Print Rotated Tree\n13. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &val);
            root = insert(root, val);
            break;
        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &val);
            root = deleteNode(root, val);
            break;
        case 3:
            printf("Enter value to search: ");
            scanf("%d", &val);
            if (search(root, val))
                printf("Found\n");
            else
                printf("Not Found\n");
            break;
        case 4:
            printf("Inorder: ");
            inorder(root);
            printf("\n");
            break;
        case 5:
            printf("Preorder: ");
            preorder(root);
            printf("\n");
            break;
        case 6:
            printf("Postorder: ");
            postorder(root);
            printf("\n");
            break;
        case 7:
            printf("Total Nodes: %d\n", countNodes(root));
            break;
        case 8:
            printf("Leaf Nodes: %d\n", countLeaves(root));
            break;
        case 9:
            printf("Height: %d\n", height(root));
            break;
        case 10:
            mirror(root);
            printf("Tree mirrored.\n");
            break;
        case 11:
            printf("Enter two values to find LCA: ");
            scanf("%d %d", &n1, &n2);
            struct Node* ancestor = lca(root, n1, n2);
            if (ancestor)
                printf("Lowest Common Ancestor: %d\n", ancestor->data);
            else
                printf("LCA not found.\n");
            break;
        case 12:
            printf("\nRotated Tree View:\n");
            printTree(root, 0);
            break;
        case 13:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}