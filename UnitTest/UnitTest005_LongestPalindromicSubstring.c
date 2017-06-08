#include <stdio.h>
#include <stdlib.h>

char* longestPalindrome(char* s) {
	int len = 0, curLen = 0;
	int h = 0, i = 0, j = 0, k = 0;
	int startIdx = 0, endIdx = 0;
	int flag = 0;
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
			i = h;
			k = len - 1;
		}
		else {
			if(i == j - 1) {
				// Find a Palindromic Substring.
				i = j - 1;
				k = len - 1;
				flag = 0;
			}
			else {
				k = j - 1;
			}
		}

		printf("i = %d, j = %d, k = %d\n", i, j, k);
		for(j = k; j > i; j--) {
			if(*(s + i) == *(s + j)) {
				printf("----i = %d, j = %d\n", i, j);
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

		if(flag == 1) {
			curLen = endIdx - startIdx + 1;
			printf("startIdx = %d\n", startIdx);
			printf("endIdx = %d\n", endIdx);
			printf("curLen = %d\n", curLen);
		}
	}

	if(curLen > 0) {
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
	//char *s = "dcefecdbaba";
	char *s = "babadcefecdbaba";

	printf("%s\n", longestPalindrome(s));
}
