/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
*/
int findBottomLeftValue(struct TreeNode* root) {
    int depth = 0; 
    int last_value = 0; 
    
    void dfs(struct TreeNode* node, int current_depth) {
        if (node == NULL) return;
        
        // If we've reached a new depth, 
        // update the last_value
        if (current_depth > depth) {
            depth = current_depth;
            last_value = node->val;
        }
        
        // Traverse right subtree first (left to right)
        dfs(node->left, current_depth + 1);
        dfs(node->right, current_depth + 1);
    }
    
    // Start DFS traversal from the root node
    dfs(root, 1); // Start at depth 1
    
    return last_value;
}
