/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 int sum(struct TreeNode* node, int *res) {
    if(node == NULL)
        return 0;

    int left = sum(node->left, res);
    int right = sum(node->right, res);

    // Case-I: when the longest path goes through the root node
    int temp = fmax(fmax(left, right) + node->val, node->val);
    // Case-II: when the longest path does not go through the root node
    int ans = fmax(temp, left + right + node->val);
    *res = fmax(ans, *res);

    return temp;
 }

int maxPathSum(struct TreeNode* root) {
    int res = INT_MIN;

    sum(root, &res);

    return res;   
}
