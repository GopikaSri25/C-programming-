bool check(struct TreeNode* root, long minimum, long maximum){
    if(root == NULL) return true;
    if(root->val <= minimum || root->val >= maximum) return false;
    return check(root->left, minimum, root->val) && check(root->right, root->val, maximum);
}
bool isValidBST(struct TreeNode* root){
    if(root == NULL) return true;
    return check(root, LONG_MIN, LONG_MAX);
}
