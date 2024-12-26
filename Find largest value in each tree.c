
void dfs(struct TreeNode* root, int* res, int *resSize, int level) {
    if(!root) return;
    if(*resSize < level) {
        *(res + *resSize) = root->val;
        (*resSize)++;
    }

    if(*(res + level - 1) < root->val) *(res + level - 1) = root->val;

    dfs(root->left, res, resSize, level + 1);
    dfs(root->right, res, resSize, level + 1);
}

int* largestValues(struct TreeNode* root, int* returnSize) {
    int *res = malloc(sizeof(int) * 10000);
    *returnSize = 0;
    dfs(root, res, returnSize, 1);

    return res;
}
