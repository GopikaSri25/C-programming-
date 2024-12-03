int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int * res = (int *)malloc(sizeof(int)*100);
    *returnSize = 0 ;
    void traversal(struct TreeNode* root , int *res , int * returnSize)
    {
        if(root != NULL)
        {
            traversal(root->left , res , returnSize);
            res[*returnSize] = root->val ; 
            (*returnSize) ++ ;
            traversal(root->right , res , returnSize);
        }
    
    }
    traversal(root , res , returnSize);
    return res;
}
