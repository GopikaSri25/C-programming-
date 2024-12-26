/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if(preorderSize == 0) return NULL;

    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node -> val = *preorder;

    int index;
    for(index = 0; *(inorder + index) != node -> val; index++);

    // build left part
    preorder++;
    node -> left = buildTree(preorder, index, inorder, index);

    // move index
    preorder = preorder + index;
    inorder = inorder + index + 1;
    index = preorderSize - index - 1;

    // build right part
    node -> right = buildTree(preorder, index, inorder, index);
    return node;
}
