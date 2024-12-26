/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

struct Node* connect(struct Node* root) {
    if (!root) return root;

    struct Node *queue[6000];
    int head = 0, tail = 0;
    
    queue[tail++] = root;
    while (head < tail) {
        int size = tail - head;
        struct Node *cur = queue[head++];;

        if (cur->left) queue[tail++] = cur->left;
        if (cur->right) queue[tail++] = cur->right;
    
        for (int i = 1; i < size; ++i) {
            struct Node *tmp = queue[head++];
            cur->next = tmp;
            cur = cur->next;

            if (tmp->left) queue[tail++] = tmp->left;
            if (tmp->right) queue[tail++] = tmp->right;
        }
    }

    return root;
}
