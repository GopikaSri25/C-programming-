typedef struct {
    char* key;
    UT_hash_handle hh;
} Hash;

typedef struct {
    char* word;
    int steps;
} QueueNode;

int ladderLength(char* beginWord, char* endWord, char** wordList,
                 int wordListSize) {
    Hash *map = NULL, *entry;
    int wordLen = strlen(beginWord), front = 0, rear = 0;
    QueueNode *queue =
                  (QueueNode*)malloc(sizeof(QueueNode) * (wordListSize + 1)),
              *curr;
    // Preprocess wordList
    for (int i = 0; i < wordListSize; i++) {
        entry = malloc(sizeof(Hash));
        // entry->key = strdup(wordList[i]);
        entry->key = wordList[i];
        HASH_ADD_STR(map, key, entry);
    }

    // Start by beginword
    queue[rear++] = (QueueNode){beginWord, 1};
    while (front < rear) {
        curr = &queue[front++];
        if (strcmp(curr->word, endWord) == 0) {
            return curr->steps;
        }
        for (int i = 0; i < wordLen; i++) {
            char tmp = curr->word[i];
            for (int j = 0; j < 26; j++) {
                if (tmp == ('a' + j))
                    continue;
                curr->word[i] = (char)('a' + j);
                HASH_FIND_STR(map, curr->word, entry);
                if (entry) {
                    queue[rear++] = (QueueNode){entry->key, curr->steps + 1};
                    HASH_DEL(map, entry);
                }
            }
            curr->word[i] = tmp;
        }
    }

    return 0;
}
