void flatten(struct TreeNode* root){
    
    // check if root exists
    if (root){
        
        struct TreeNode* temp = root->right;    // store the right part of root
        
        root->right = root->left;           // move the left part to the right
        root->left = NULL;                  // clear left part
        
        struct TreeNode* curr = root;
        while(curr->right){                 // use while loop to find the bottom right side
            curr = curr->right;
        }
        curr->right = temp;                 // attach temp back
        
        // recursion
        flatten(root->right);
    }

}
