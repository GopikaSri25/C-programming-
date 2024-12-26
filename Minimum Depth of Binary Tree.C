/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct Queue {
    struct TreeNode** nodes; // Array of pointers to TreeNode
    int front;               // Index of the front element
    int rear;                // Index of the rear element
    int size;                // Current number of elements in the queue
    int capacity;            // Maximum number of elements the queue can hold
} queue;

queue* createQueue(int capacity) {
    queue* q = (queue*)malloc(sizeof(queue));
    q->capacity = capacity;
    q->size = 0;
    q->front = 0;
    q->rear = capacity - 1;
    q->nodes = (struct TreeNode**)malloc(capacity * sizeof(struct TreeNode*));
    return q;
}

bool isEmpty(queue* q) { 
    return q->size == 0;
}

bool isFull(queue* q) { 
    return q->size == q->capacity;
}

void push(queue* q, struct TreeNode* node) {
    if (isFull(q))
        return;
    q->rear = (q->rear + 1) % (q->capacity);
    q->nodes[q->rear] = node;
    q->size++;
}

struct TreeNode* pop(queue* q) {
    if (isEmpty(q))
        return NULL;

    struct TreeNode* node = q->nodes[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return node;
}

void freeQueue(queue* q) {
    free(q->nodes);
    free(q);
}

int minDepth(struct TreeNode* root) {
    if(!root)
        return 0;
    
    queue* q = createQueue(100001);
    int cnt = 0;
    push(q, root);
    while(!isEmpty(q)){
        cnt++;
        int n = q->size;
        int u = 0;
        while(u < n){
            struct TreeNode* node = pop(q);
            if(!node->left && !node->right)
                return cnt;
            if(node->left)
                push(q, node->left);
            if(node->right)
                push(q, node->right);
            u++;
        }
    }
    freeQueue(q);
    return -1;
}
