/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define QUEUE_SIZE 2001

typedef struct
{
    int front;
    int rear;
    int size;
    struct TreeNode ** queue_arr;
}queue;

bool isQueueEmpty(queue * Queue)
{
    return (Queue->front == -1) ? true :  false;
}

bool isQueueFull(queue * Queue)
{
    return (Queue->rear == Queue->size - 1) ? true : false;
}

void enqueue(queue * Queue, struct TreeNode * node)
{
    if(isQueueFull(Queue))
        return;

    Queue->queue_arr[++Queue->rear] = node;
    if(Queue->front == -1)
        Queue->front = 0;
    return;
}

struct TreeNode * dequeue(queue * Queue)
{
    if(isQueueEmpty(Queue))
        return NULL;

    struct TreeNode * ret_node = Queue->queue_arr[Queue->front];
    if(Queue->front == Queue->rear)
    {
        Queue->front = -1;
        Queue->rear = -1;
    }
    else
    {
        ++Queue->front;
    }
    return ret_node;
}

int find_height(struct TreeNode * root)
{
    if(root)
    {
        int lchild_ht = find_height(root->left);
        int rchild_ht = find_height(root->right);

        return (lchild_ht >= rchild_ht) ? (lchild_ht + 1) : (rchild_ht + 1);
    }
    return 0;
}

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes) 
{
    if(!root)
    {
        *returnSize = 0;
        return NULL;
    }    

    int i=0;
    int height = find_height(root);

    int ** ret_arr = (int **)malloc(sizeof(int *) * height);
    for(i=0; i<height; i++)
    {
        ret_arr[i] = NULL;
    }

    int * col_arr = (int *)malloc(sizeof(int) * height);
    for(i=0; i<height; i++)
    {
        col_arr[i] = 0;
    }

    queue Queue;
    Queue.front = -1;
    Queue.rear = -1;
    Queue.size = QUEUE_SIZE;
    Queue.queue_arr = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * Queue.size);

          
    //Enqueue the root node
    enqueue(&Queue, root);
    int level = 0;


    while(isQueueEmpty(&Queue) == false)
    {
        int num_of_elements_in_queue = Queue.rear - Queue.front + 1;

        while(num_of_elements_in_queue > 0)
        {
            if(ret_arr[level] == NULL)
            {
                ret_arr[level] = (int *)malloc(sizeof(int) * num_of_elements_in_queue);
            }
            int col_index = col_arr[level];

            struct TreeNode * dequeue_element = dequeue(&Queue);
            ret_arr[level][col_index] = dequeue_element->val;
            col_arr[level] += 1;

            if(dequeue_element->left)
            {
                enqueue(&Queue, dequeue_element->left);
            }

            if(dequeue_element->right)
            {
                enqueue(&Queue, dequeue_element->right);
            }

            num_of_elements_in_queue--;
        }
        level++;
    }



    //Swap the items
    for(i=0; i<level/2; i++)
    {
        int * tmp_ptr = ret_arr[i];
        int col_num = col_arr[i];

        ret_arr[i] = ret_arr[level-i-1];
        ret_arr[level-i-1] = tmp_ptr;

        col_arr[i] = col_arr[level-i-1];
        col_arr[level-i-1] = col_num;
    }


    *returnSize = level;
    *returnColumnSizes = col_arr;
    return ret_arr;
}
