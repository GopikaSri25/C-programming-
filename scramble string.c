bool isScramble(const char * const s1, const char * const s2){
	assert(s1 != NULL && s2 != NULL);

	const int totalLen = strlen(s1);
	if ( totalLen != strlen(s2) ){
		return false;
	}
	if (0 == totalLen){
		return true;
	}

	bool dp[totalLen + 1][totalLen][totalLen];	//dp[0] is unused.
	for (int i = 0; i < totalLen; i += 1){
		for (int j = 0; j < totalLen; j += 1){
			dp[1][i][j] = (s1[i] == s2[j]);
		}
	}

	for (int partLen = 2; partLen <= totalLen; partLen += 1){

		const int border = totalLen - (partLen - 1);
		for (int i = 0; i < border; i += 1){
			for (int j = 0; j < border; j += 1){

				bool matched = false;
				for (int leftLen = 1; leftLen < partLen; leftLen += 1){
					const int rightLen = partLen - leftLen;
					if (
						( dp[leftLen][i][j] && dp[rightLen][i + leftLen][j + leftLen] ) ||
						( dp[rightLen][i + leftLen][j] && dp[leftLen][i][j + rightLen] )
					){
						matched = true;
						break;
					}
				}
				dp[partLen][i][j] = matched;

			}
		}

	}

	return dp[totalLen][0][0];
}
