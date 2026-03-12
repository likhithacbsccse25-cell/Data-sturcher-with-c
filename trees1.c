#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) return createNode(data); 
    
    if (root->left == NULL) 
        root->left = createNode(data);
    else if (root->right == NULL)
        root->right = createNode(data);
    else
        insert(root->left, data);
        
    return root;
}

void pre_order_traversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data); 
        pre_order_traversal(root->left);
        pre_order_traversal(root->right);
    }
}

int main() {
    struct TreeNode* root = NULL;
    root = insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 50);
    
    printf("Pre_order Traversal: "); 
    pre_order_traversal(root);
    return 0;
}
