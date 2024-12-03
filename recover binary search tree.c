
void traversal(struct TreeNode * root, struct TreeNode ** prev_node, struct TreeNode ** first_swap_node, struct TreeNode ** second_swap_node)
{
    if(root)
    {
        traversal(root->left, prev_node, first_swap_node, second_swap_node);

        if((*prev_node != NULL) && (root->val <= (*prev_node)->val))
        {
            if(*first_swap_node == NULL)
            {
                *first_swap_node = *prev_node;
                *second_swap_node = root;
            }
            else
            {
                *second_swap_node = root;
            }
        }

        *prev_node = root;

        traversal(root->right, prev_node, first_swap_node, second_swap_node);
    }
}

void recoverTree(struct TreeNode* root) 
{
    struct TreeNode * first_swap_node = NULL;
    struct TreeNode * second_swap_node = NULL;
    struct TreeNode * prev_node = NULL;

    traversal(root, &prev_node, &first_swap_node, &second_swap_node);

    //Swap the value of two nodes
    int tmp_val = first_swap_node->val;
    first_swap_node->val = second_swap_node->val;
    second_swap_node->val = tmp_val;
    return;

    
}
