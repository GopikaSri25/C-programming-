#define min(a, b) ((a) < (b) ? (a) : (b))

// Helper function to calculate the minimum distance between two characters on the ring
int distance(char a, char b) {
    return min(abs(a - b), 26 - abs(a - b));
}

int dp[101][101];

// Recursive function to calculate the minimum steps required
int dfs(char *ring, char *key, int ring_len, int key_len, int ring_idx, int key_idx) {
    // If all characters in the key are spelled, return 0
    if (key_idx == key_len) return 0;
    // If the current state is already calculated, return it from the memoization table
    if (dp[key_idx][ring_idx] != -1) return dp[key_idx][ring_idx];

    // Calculate the minimum steps required for the current state
    int min_steps = 1e9; // Initialize to a large value
    for (int i = 0; i < ring_len; i++) {
        if (ring[i] == key[key_idx]) {
            // Calculate the distance to rotate clockwise and counterclockwise
            int clockwise = (ring_idx + ring_len - i) % ring_len;
            int counterclockwise = (i + ring_len - ring_idx) % ring_len;
            // Recursively calculate the minimum steps for the next character
            int steps = min(clockwise, counterclockwise) + 1 + dfs(ring, key, ring_len, key_len, i, key_idx + 1);
            // Update the minimum steps
            min_steps = min(min_steps, steps);
        }
    }
    // Store the result in the memoization table
    dp[key_idx][ring_idx] = min_steps;
    return min_steps;
}

int findRotateSteps(char* ring, char* key) {
    int ring_len = strlen(ring);
    int key_len = strlen(key);

    // Initialize the memoization table with -1
    memset(dp, -1, sizeof(dp));

    // Start the recursive function from the beginning of the ring and key
    return dfs(ring, key, ring_len, key_len, 0, 0);
}
