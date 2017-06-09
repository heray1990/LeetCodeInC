#include <stdio.h>
#include <stdlib.h>

char* longestPalindrome(char* s) {
	int len = 0, curLen = 0;
	int h = 0, i = 0, j = 0, k = 0;
	int startIdx = 0, endIdx = 0;
	int flag = 0, subStrFound = 0;
	char* retStr = NULL;

	// Get the length of string s.
	while(*(s + len) != '\0') {
		len++;
	}

	if(len == 1) {
		return s;
	}

	for(i = 0; i < len; i++) {
		if(flag == 0) {
			k = len - 1;
			if(subStrFound == 0) {
				i = h;
				startIdx = 0;
				endIdx = 0;
			}
		}
		else {
			if(subStrFound > 0) {
				h = i;
				k = len - 1;
				flag = 0;
			}
			else {
				k = j - 1;
			}
		}

		for(j = k; j > i; j--) {
			if(*(s + i) == *(s + j)) {
				if(flag == 0) {
					if(curLen < j - i + 1) {
						startIdx = i;
						endIdx = j;
					}
				}

				flag = 1;
				break;
			}
			else {
				if(flag == 1) {
					h++;
					flag = 0;
					break;
				}
			}
		}

		if((flag == 1) && (j - i <=2)) {
			// A Palindromic Substring is found.
			subStrFound = 1;

			curLen = endIdx - startIdx + 1;
			printf("A Palindromic Substring is found.\n");
			printf("startIdx = %d\n", startIdx);
			printf("endIdx = %d\n", endIdx);
			printf("curLen = %d\n", curLen);
		}
	}

	if(curLen > 0) {
		printf("Longest Palindromic Substring: startIdx = %d\n", startIdx);
		printf("Longest Palindromic Substring: endIdx = %d\n", endIdx);
		printf("Longest Palindromic Substring: curLen = %d\n", curLen);
		retStr = malloc(curLen * sizeof(char));

		for(i = startIdx; i <= endIdx; i++) {
			*(retStr + i - startIdx) = *(s + i);
		}
	}
	else {
		printf("There is not palindromic substring in string s.\n");
	}

	return retStr;
}

int main() {
	//char *s = "babadcefecdbaba";
	int i = 0;
	char *s = "abacca";
	char *res = longestPalindrome(s);

	printf("\nInput: ");
	while(*(s + i) != '\0') {
		printf("%c", *(s + i));
		i++;
	}
	printf("\nOutput: %s\n", res);
}
