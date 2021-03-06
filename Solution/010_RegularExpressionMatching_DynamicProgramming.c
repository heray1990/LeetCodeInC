bool isMatch(const char *s, const char *p) {
	int i = 0, j = 0;
	int sLen = strlen(s);
	int pLen = strlen(p);
	bool res = false;
	bool **table = NULL;

	if(sLen == 0 && pLen == 0)
		return true;

	if(pLen == 0)
		return false;

	// Initialize table with false.
	table = (bool **)malloc((pLen + 1) * sizeof(bool*));
	for(j = 0; j <= pLen; j++) {
		*(table + j) = (bool *)malloc((sLen + 1) * sizeof(bool));
	}
	for(j = 0; j <= pLen; j++) {
		for(i = 0; i <= sLen; i++) {
			table[j][i] = false;
		}
	}

	table[0][0] = true;
	i = 0;
	j = 0;

	for(j = 0; j < pLen; j++) {
		if(p[j] != '*') {
			for(i = 0; i < sLen; i++) {
				if(s[i] == p[j] || p[j] == '.') {
					table[j + 1][i + 1] = table[j][i];
				}
			}
		}
		else {
			if(j > 0) {
				if(table[j - 1][0])
					table[j + 1][0] = true;
				if(p[j - 1] == '.') {
					i = 0;
					while(i < sLen && !table[j - 1][i + 1] 
						&& !table[j][i + 1]) {
						i++;
					}

					for(; i < sLen; i++) {
						table[j + 1][i + 1] = true;
					}
				}
				else {
					for(i = 0; i < sLen; i++) {
						if(table[j - 1][i + 1] || table[j][i + 1]
							|| i > 0 && j > 0 && table[j + 1][i]
							&& s[i] == s[i - 1] && s[i - 1] == p[j - 1]) {
							table[j + 1][i + 1] = true;
						}
					}
				}
			}
		}
	}

	res = table[pLen][sLen];

	for(j = 0; j <= pLen; j++) {
		free(*(table + j));
		*(table + j) = NULL;
	}
	free(table);
	table = NULL;

	return res;
}
