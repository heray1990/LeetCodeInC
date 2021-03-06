char* longestPalindrome(char* s) {
	int sLen = 0, scanLen = 0;
	int i = 0, j = 0, m = 0, n = 0;
	int startIdx = 0;
	int charMatch = 0;
	char* retStr = NULL;

	// Get the length of string s.
	while(*(s + sLen) != '\0') {
		sLen++;
	}

	if(sLen == 1) {
		return s;
	}

	scanLen = sLen;

	for(i = 0; i <= sLen - scanLen; i++) {
		if(scanLen % 2 == 0) {
			j = (i + i + scanLen - 1) / 2;
		}
		else {
			j = (i + i + scanLen - 1) / 2 - 1;
		}

		n = i + scanLen - 1;
		for(m = i; m <= j; m++) {
			if(*(s + m) == *(s + n)) {
				charMatch++;
				n--;
			}
			else {
				charMatch = 0;
			}

			if(charMatch == 0) {
				break;
			}
		}

		if((n - m <= 2) && (charMatch > 0)) {
			break;
		}

		if(i + scanLen == sLen) {
			i = -1;
			scanLen--;
			if(scanLen <= 1) {
				break;
			}
		}
	}

	if(charMatch > 0) {
		startIdx = m - scanLen / 2;
		retStr = (char*)malloc((scanLen + 1) * sizeof(char));

		for(i = startIdx; i < startIdx + scanLen; i++) {
			*(retStr + i - startIdx) = *(s + i);
		}
		
		*(retStr + scanLen) = '\0';
	}
	else {
		retStr = (char*)malloc(2 * sizeof(char));
		*retStr = *s;
		*(retStr + 1) = '\0';
	}

	return retStr;
}