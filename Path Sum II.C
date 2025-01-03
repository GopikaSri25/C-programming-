bool hasPathSum(struct TreeNode* root, int targetSum,int **arr, int *i, int j,int *returnColumnSizes){
if(root==NULL) return false;
if(root->left ==NULL && root->right==NULL && targetSum-root->val==0)
{  
    arr[(*i)]=malloc(sizeof(int)*(j+1)); // allocating memory equal to depth of that path(j keeps the track of the depth)
    returnColumnSizes[(*i)]=j+1;        // *i is the variable to keep track of no. of rows in the arr i.e its *returnSize variable
    arr[(*i)++][j]=root->val;           // adding the leaf to the ans 
    return true;   
}
if(root->left==NULL && root->right==NULL && targetSum-root->val!=0) return false;
bool found1=false,found2=false;
int row =*i,k=0;
found1=hasPathSum(root->left,targetSum-root->val,arr,i,j+1,returnColumnSizes); 
if(found1) // if a valid path has been found
{
    while(row<*i) 
        // while back tracking if more than 1 path may exists from any intermediate node i.e a node is common to many paths 
        // and has to be added in all ....row will take care of it.
        // while down the recursion row was set to *i and at every leaf if its a valid path *i will be incremented 
        // and during the backtracking when the function call returns to this node,the node's value has to be added in all the  
        // paths that has been found. So, a while(row<*i ) is being run. Note : root->val is being added from backwards as per their depth
        // and the depth of a node from root will be constant in all the paths that has been found
        //(Hope you can understand it with my poor explanation :)
    {
        arr[row++][j]=root->val;
 
    }
}
    // doing the same stuff as above for the right half
row=*i;
found2=hasPathSum(root->right,targetSum-root->val,arr,i,j+1,returnColumnSizes);
if(found2)
{
     while(row<*i)
    {
        arr[row++][j]=root->val;
    
    }
}

return found1 || found2;  
}
int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes){
    int **arr;
    bool found;
    arr=malloc(sizeof(int*)*2500);
    *returnSize=0; 
    *returnColumnSizes=malloc(sizeof(int)*2500);
    found = hasPathSum(root,targetSum,arr,returnSize,0,*returnColumnSizes);
    return arr;  
}
