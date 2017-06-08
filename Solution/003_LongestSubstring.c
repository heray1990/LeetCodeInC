int lengthOfLongestSubstring(char* s) {
	int startidx = 0;
	int len = 0;
	int i = 0, j = 0;
	int retval = 0;

	// length of s
	while(*(s + len) != '\0') {
		len++;
	}

	for(i = 1; i < len; i++) {
		for(j = i - 1; j >= startidx; j--) {
			if(*(s + i) == *(s + j)) {
				startidx = j + 1;
				if(retval < i - j) {
					retval = i - j;
				}
				break;
			}
			else {
				if(j == startidx) {
					if(retval < i - j + 1) {
						retval = i - j + 1;
					}
				}
			}
		}

		/* Break the loop when the length of remaind items is smaller than
		 * retval.
		 */
		if(len - startidx < retval) {
			break;
		}
	}

	// There is no repeating characters in s.
	if(retval == 0) {
		retval = len;
	}

	return retval;
}
