// Runtime 51 ms Beats 31.58% Memory 30.6 MB Beats 15.79%
struct HashTable {
    char key[11]; 
    int val; 
    UT_hash_handle hh;
};

struct HashTable* freq;

struct HashTable* find(char* key) {
    struct HashTable* temp;
    HASH_FIND_STR(freq, key, temp);
    return temp;
}
int insert(char* key) {
    struct HashTable* it = find(key);
    if (it == NULL) {
        struct HashTable* temp = (struct HashTable*)malloc(sizeof(struct HashTable));
        strcpy(temp->key, key);
        temp->val = 1;

        HASH_ADD_STR(freq, key, temp);
        
        return temp->val;
    }
    else {
        (it->val)++;
        return it->val;
    }
    return -1;
}
void delete_all() {
    struct HashTable* curr, *temp;
    HASH_ITER(hh, freq, curr, temp) {
        HASH_DEL(freq, curr);
        free(curr);
    }
}

void substr(char* dst, const char* src, unsigned int start, unsigned int count) {
    strncpy(dst, src + start, count);
    dst[count] = '\0';
}
char** findRepeatedDnaSequences(char* s, int* returnSize) {
    // Hashtable
    // use a hashtable to count the frequencies of all the 10-letter-long sequences,
    // and return those occur more than once. 

    // Time complexity: O(n*L)
    // Space complexity: O(n*L)

    const int n = strlen(s);
    if (n < 10) {
        *returnSize = 0;
        return NULL;
    }
    char** temp = (char**)calloc(n - 10 + 1, sizeof(char*));
    for (int i = 0; i + 10 < n + 1; ++i) {
        temp[i] = (char*)calloc(11, sizeof(char));
    }
    int size = 0;

    struct HashTable* freq = NULL;

    char* sub = (char*)calloc(11, sizeof(char));
    for (int i = 0; i + 10 < n + 1; ++i) {
        substr(sub, s, i, 10);
        if (insert(sub) == 2) {
            strcpy(temp[size++], sub);
        }
    }
    
    char** result = (char**)calloc(size, sizeof(char*));
    *returnSize = size;
    for (int i = 0; i < size; ++i) {
        result[i] = (char*)calloc(11, sizeof(char));
        strcpy(result[i], temp[i]);
    }

    for (int i = 0; i + 10 < n + 1; ++i) {
        free(temp[i]);
    }
    free(temp);
    free(sub);
    delete_all();  // Remember to delete the Hashtable in the end!!
    return result;
}
