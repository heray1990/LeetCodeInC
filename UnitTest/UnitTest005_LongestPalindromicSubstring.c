#include <stdio.h>
#include <stdlib.h>

char* longestPalindrome(char* s) {
	int sLen = 0, scanLen = 0;
	int i = 0, j = 0, k = 0, m = 0, n = 0;
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
			k = j + 1;
		}
		else {
			j = (i + i + scanLen - 1) / 2 - 1;
			k = j + 2;
		}

		n = i + scanLen - 1;
		printf("i = %d, j = %d, k = %d, scanLen = %d\n", i, j, k, scanLen);
		for(m = i; m <= j; m++) {
			printf("m = %d, n = %d\n", m, n);
			if(*(s + m) == *(s + n)) {
				charMatch++;
				printf("s[%d] == s[%d], charMatch = %d\n", m, n, charMatch);
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
		printf("m = %d\n", m);
		startIdx = m - scanLen / 2;
		printf("Longest Palindromic Substring: startIdx = %d\n", startIdx);
		printf("Longest Palindromic Substring: length = %d\n", scanLen);
		retStr = malloc(scanLen * sizeof(char));

		for(i = startIdx; i < startIdx + scanLen; i++) {
			*(retStr + i - startIdx) = *(s + i);
		}
	}
	else {
		printf("There is repeating characters in string s. Pick first character as the Palindromic Substring.\n");
		retStr = malloc(sizeof(char));
		*retStr = *s;
	}

	return retStr;
}

int main() {
	int i = 0;
	char *s = "babadcefecdbaba";
	//char *s = "abcda";
	char *res = longestPalindrome(s);

	printf("\nInput: ");
	while(*(s + i) != '\0') {
		printf("%c", *(s + i));
		i++;
	}
	printf("\nOutput: %s\n", res);

	free(res);
	res = NULL;
}
