struct Node * getNode(struct Node *cur, struct Node *cache[]){
    if(!cur) return cur;

    if(!cache[cur->val]){
        cache[cur->val] = (struct Node *) malloc (sizeof(struct Node));
        cache[cur->val]->val = cur->val;
        cache[cur->val]->numNeighbors = cur->numNeighbors;
        cache[cur->val]->neighbors = NULL;
    }

    return cache[cur->val];
}

struct Node * dfs(struct Node *cur, struct Node *cache[]){
    if(!cur) return cur;

    if(cache[cur->val])
        return cache[cur->val];
    
    cache[cur->val] = getNode(cur, cache);
    cache[cur->val]->neighbors = (struct Node**) malloc (sizeof(struct Node*)*cur->numNeighbors);
    for(int i=0; i<cur->numNeighbors; ++i){
        struct Node *adj = cur->neighbors[i];
        if(!cache[adj->val]){
            cache[adj->val] = dfs(adj, cache);
        }
        cache[cur->val]->neighbors[i] = cache[adj->val];
    }

    return cache[cur->val];
}

struct Node * bfs(struct Node *root, struct Node *cache[]){
    struct Node *que[101];
    for(int i=0; i<101; ++i)
        que[i] = NULL;
    int fPtr = 0;
    int ePtr = 0;

    que[ePtr] = root;
    cache[root->val] = getNode(root, cache);

    while(fPtr <= ePtr && que[fPtr]){
        struct Node *front = que[fPtr ++];
        cache[front->val]->neighbors = (struct Nodee **) malloc (sizeof(struct Node*) * front->numNeighbors);

        for(int i=0; i<front->numNeighbors; ++i){
            struct Node *adj = front->neighbors[i];
            if(!cache[adj->val]){
                cache[adj->val] = getNode(adj, cache);
                que[++ ePtr] = adj;
            }

            cache[front->val]->neighbors[i] = cache[adj->val];
        }
    }

    return cache[root->val];
}

struct Node *cloneGraph(struct Node *s) {
    if(!s) return s;

    // init cache;
    struct Node *cache[101];
    for(int i=0; i<101; ++i)
        cache[i] = NULL;

    return bfs(s, cache);
    return dfs(s, cache);
}
