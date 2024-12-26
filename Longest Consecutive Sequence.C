#include <assert.h>
#include <stdlib.h>
// #include "uthash.h"

/// An entry in a hash table.
///
/// The entry is hashed on its `id`, and acts as a doubly-linked list
/// where the sum of all `value` in the list is the length of a
/// consecutive sequence.
typedef struct _entry
{
    int id;
    int value;
    struct _entry *prev;
    struct _entry *next;
    UT_hash_handle hh;
} entry_t;

static entry_t *entries_find(entry_t *entries, int entry_id)
{
    entry_t *entry;
    HASH_FIND_INT(entries, &entry_id, entry);
    return entry;
}

int longestConsecutive(const int *nums, int nums_len)
{
    entry_t *entries = NULL;
    entry_t *entries_store = (entry_t *)malloc(nums_len * sizeof(entry_t));
    assert(("Failed to allocate block of entries.", entries_store));

    // First pass, build the hash table.
    for (int i = 0; i < nums_len; ++i)
    {
        int current = nums[i];
        if (entries_find(entries, current))
        {
            continue;
        }

        entry_t *entry = entries_store + i;
        *entry = (entry_t){.id = nums[i],
                           .value = 1,
                           .prev = entries_find(entries, current - 1),
                           .next = entries_find(entries, current + 1)};
        if (entry->prev)
        {
            entry->prev->next = entry;
        }
        if (entry->next)
        {
            entry->next->prev = entry;
        }
        HASH_ADD_INT(entries, id, entry);
    }

    // Second pass, destructively iterate through the hash table to
    // calculate the longest consecutive sequence.
    int result = 0;
    entry_t *curr, *temp;
    HASH_ITER(hh, entries, curr, temp)
    {
        HASH_DEL(entries, curr);
        if (curr->prev)
        {
            curr->prev->next = curr->next;
            curr->prev->value += curr->value;
        }
        if (curr->next)
        {
            curr->next->prev = curr->prev;
            curr->next->value += curr->prev ? 0 : curr->value;
        }
        if (curr->value > result)
        {
            result = curr->value;
        }
    }

    free(entries_store);
    return result;
} // int longestConsecutive(const int *, int);
