#include <stdio.h>
#include <string.h>

typedef enum {
	false,
	true
} bool;

bool helper(const char *s, const char *p, int i, int j) {
	int sLen = strlen(s);
	int pLen = strlen(p);

	if(j == pLen)
		return i == sLen;

	if((j == pLen - 1) || (p[j + 1] != '*')) {
		if((i == sLen) || ((s[i] != p[j]) && (p[j] != '.')))
			return false;
		else {
			return helper(s, p, i + 1, j + 1);
		}
	}

	// p[j + 1] == '*'
	while((i < sLen) && ((p[j] == '.') || (s[i] == p[j]))) {
		if(helper(s, p, i, j + 2))
			return true;
		i++;
	}

	return helper(s, p, i, j + 2);
}

bool isMatch(const char *s, const char *p) {
	return helper(s, p, 0, 0);
}

int main() {
	const char *s = "aab";
	const char *p = "a*b*";

	printf("Input:\"%s\", \"%s\"\n", s, p);
	if(isMatch(s, p) == 1) {
		printf("Output: True\n");
	}
	else {
		printf("Output: False\n");
	}

	return 1;
}
