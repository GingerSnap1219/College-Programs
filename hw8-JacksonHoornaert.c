// Jackson Hoornaert
// CSCI 330 - HW 8
// This program reads integers from "hw8.data", builds a binary search tree,
// creates a linked list pointing to the same nodes, and performs various traversals.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct ListNode {
    Node *treeNode;
    struct ListNode *next;
} ListNode;

// Function prototypes
Node* insertTreeNode(Node* root, int data);
void appendListNode(ListNode** head, Node* treeNode);
void preOrderTraversal(Node* root);
void inOrderTraversal(Node* root);
void postOrderTraversal(Node* root);
void listTraversal(ListNode* head);
void freeTree(Node* root);
void freeList(ListNode* head);

int main() {
    FILE *file = fopen("hw8.data", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    Node *root = NULL;
    ListNode *listHead = NULL;

    int data;
    while (fscanf(file, "%d", &data) != EOF) {
        // Insert node into binary tree
        root = insertTreeNode(root, data);
        // Append node to linked list
        appendListNode(&listHead, root);
    }

    fclose(file);

    // Perform traversals
    printf("Pre-order Traversal of Tree:\n");
    preOrderTraversal(root);
    printf("\n\nIn-order Traversal of Tree:\n");
    inOrderTraversal(root);
    printf("\n\nPost-order Traversal of Tree:\n");
    postOrderTraversal(root);
    printf("\n\nTraversal of Linked List:\n");
    listTraversal(listHead);

    // Free memory
    freeTree(root);
    freeList(listHead);

    return 0;
}

// Insert a node into the binary search tree
Node* insertTreeNode(Node* root, int data) {
    if (root == NULL) {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (data < root->data)
        root->left = insertTreeNode(root->left, data);
    else
        root->right = insertTreeNode(root->right, data);
    return root;
}

// Append a node to the linked list pointing to the tree node
void appendListNode(ListNode** head, Node* treeNode) {
    ListNode *newListNode = (ListNode *)malloc(sizeof(ListNode));
    newListNode->treeNode = treeNode;
    newListNode->next = NULL;

    if (*head == NULL) {
        *head = newListNode;
    } else {
        ListNode *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newListNode;
    }
}

// Pre-order traversal of the binary tree
void preOrderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// In-order traversal of the binary tree
void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Post-order traversal of the binary tree
void postOrderTraversal(Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Traversal of the linked list
void listTraversal(ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->treeNode->data);
        head = head->next;
    }
}

// Free all nodes in the binary tree
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Free all nodes in the linked list
void freeList(ListNode* head) {
    ListNode *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
