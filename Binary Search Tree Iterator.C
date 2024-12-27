typedef struct {
    struct TreeNode** stack; // Stack to store the nodes for in-order traversal
    int top; // Index of the top element in the stack
} BSTIterator;

void push(BSTIterator* iter, struct TreeNode* node) {
    while (node) { // Traverse to the leftmost node
        iter->stack[++(iter->top)] = node; // Push the node onto the stack
        node = node->left; // Move to the left child
    }
}

BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator* iter = (BSTIterator*)malloc(sizeof(BSTIterator)); // Allocate memory for the iterator
    iter->stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 10000); // Allocate memory for the stack
    iter->top = -1; // Initialize the top index
    push(iter, root); // Push the root and its left descendants onto the stack
    return iter; // Return the created iterator
}

int bSTIteratorNext(BSTIterator* iter) {
    struct TreeNode* node = iter->stack[(iter->top)--]; // Pop the top node from the stack
    int result = node->val; // Store the value of the node
    push(iter, node->right); // Push the right child and its left descendants onto the stack
    return result; // Return the value of the node
}

bool bSTIteratorHasNext(BSTIterator* iter) {
    return iter->top != -1; // Check if there are more nodes to visit
}

void bSTIteratorFree(BSTIterator* iter) {
    free(iter->stack); // Free the memory allocated for the stack
    free(iter); // Free the memory allocated for the iterator
}
