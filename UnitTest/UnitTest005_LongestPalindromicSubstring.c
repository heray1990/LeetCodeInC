#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 0 
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
		//printf("i = %d, j = %d, scanLen = %d\n", i, j, scanLen);
		for(m = i; m <= j; m++) {
			//printf("m = %d, n = %d\n", m, n);
			if(*(s + m) == *(s + n)) {
				charMatch++;
				//printf("s[%d] == s[%d], charMatch = %d\n", m, n, charMatch);
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
		//printf("m = %d\n", m);
		startIdx = m - scanLen / 2;
		//printf("Longest Palindromic Substring: startIdx = %d\n", startIdx);
		//printf("Longest Palindromic Substring: length = %d\n", scanLen);
		retStr = (char*)malloc((scanLen + 1) * sizeof(char));

		for(i = startIdx; i < startIdx + scanLen; i++) {
			*(retStr + i - startIdx) = *(s + i);
		}
		
		*(retStr + scanLen) = '\0';
	}
	else {
		//printf("There is repeating characters in string s. Pick first character as the Palindromic Substring.\n");
		retStr = (char*)malloc(2 * sizeof(char));
		*retStr = *s;
		*(retStr + 1) = '\0';
	}

	return retStr;
}
#else
char* longestPalindrome(char* s) {
	int sLen = strlen(s);
	int **p = NULL;
	int i = 0, j = 0, k = 0;
	char *result = NULL;

	if(sLen == 0)
		return "";
	if(sLen == 1)
		return s;

	p = (int **)malloc(sLen * sizeof(int *));
	for(i = 0; i < sLen; i++) {
		*(p + i) = (int *)malloc(sLen * sizeof(int));
	}
	for(i = 0; i < sLen; i++) {
		for(j = 0; j < sLen; j++) {
			p[i][j] = 0;
		}
	}

	// Base case
	for(i = 0; i < sLen; i++) {
		p[i][i] = 1;

		if(i < sLen - 1 && s[i] == s[i + 1])
			p[i][i + 1] = 1;
	}

	for(i = sLen - 2; i >= 0; i--) {
		for(j = i + 1; j < sLen; j++) {
			if(p[i + 1][j - 1] == 1 && s[i] == s[j])
				p[i][j] = 1;
		}
	}

	for(k = sLen - 1; k > 0; k--) {
		for(i = 0, j = k; i < sLen - k; i++, j++) {
			//printf("i = %d, j = %d, p[i][j] = %d\n", i, j, p[i][j]);
			if(p[i][j] == 1)
				break;
		}
		if(i >= sLen || j >= sLen)
			continue;
		if(p[i][j] == 1)
			break;
	}

	//printf("i = %d, j = %d, p[i][j] = %d\n", i, j, p[i][j]);
	for(k = 0; k < sLen; k++) {
		free(*(p + k));
		*(p + k) = NULL;
	}
	free(p);
	p = NULL;

	result = (char *)malloc((j - i + 2) * sizeof(char));

	for(k = i; k < j + 1; k++) {
		result[k - i] = s[k];
	}
	result[j - i + 1] = '\0';

	return result;
}
#endif

int main() {
	int i = 0;
	//char *s = "babadcefecdbaba";
	//char *s = "cbbd";
	char *s ="zudfweormatjycujjirzjpyrmaxurectxrtqedmmgergwdvjmjtstdhcihacqnothgttgqfywcpgnuvwglvfiuxteopoyizgehkwuvvkqxbnufkcbodlhdmbqyghkojrgokpwdhtdrwmvdegwycecrgjvuexlguayzcammupgeskrvpthrmwqaqsdcgycdupykppiyhwzwcplivjnnvwhqkkxildtyjltklcokcrgqnnwzzeuqioyahqpuskkpbxhvzvqyhlegmoviogzwuiqahiouhnecjwysmtarjjdjqdrkljawzasriouuiqkcwwqsxifbndjmyprdozhwaoibpqrthpcjphgsfbeqrqqoqiqqdicvybzxhklehzzapbvcyleljawowluqgxxwlrymzojshlwkmzwpixgfjljkmwdtjeabgyrpbqyyykmoaqdambpkyyvukalbrzoyoufjqeftniddsfqnilxlplselqatdgjziphvrbokofvuerpsvqmzakbyzxtxvyanvjpfyvyiivqusfrsufjanmfibgrkwtiuoykiavpbqeyfsuteuxxjiyxvlvgmehycdvxdorpepmsinvmyzeqeiikajopqedyopirmhymozernxzaueljjrhcsofwyddkpnvcvzixdjknikyhzmstvbducjcoyoeoaqruuewclzqqqxzpgykrkygxnmlsrjudoaejxkipkgmcoqtxhelvsizgdwdyjwuumazxfstoaxeqqxoqezakdqjwpkrbldpcbbxexquqrznavcrprnydufsidakvrpuzgfisdxreldbqfizngtrilnbqboxwmwienlkmmiuifrvytukcqcpeqdwwucymgvyrektsnfijdcdoawbcwkkjkqwzffnuqituihjaklvthulmcjrhqcyzvekzqlxgddjoir";

	printf("\nInput: ");
	while(*(s + i) != '\0') {
		printf("%c", *(s + i));
		i++;
	}
	printf("\n");

	char *res = longestPalindrome(s);
	printf("Output: %s\n", res);

	free(res);
	res = NULL;

	return 1;
}
