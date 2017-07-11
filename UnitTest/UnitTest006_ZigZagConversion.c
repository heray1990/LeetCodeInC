#include <stdio.h>
#include <stdlib.h>

char* convert(char* s, int numRows) {
	if(numRows<2)
		return s;    
	int len = strlen(s), num = 0, diff;
	int width = (numRows - 1) * 2;
	char* ans = (char*)malloc(sizeof(char) * (len + 1));

	for(int k = 0; k < numRows; k++){
		diff = k * 2;

		for(int h = k; h < len; h = h + diff, num++){
			*(ans + num) = *(s + h);
			diff = (diff == k * 2 ? width - k * 2 : k * 2);

			if(diff == 0)
				diff = width;
		}
	}
	*(ans+len) = '\0';

	return ans;
}

int main() {
	int numRows = 3;
	int sLen = 0;
	char *s = "PAYPALISHIRING";
	char *retStr = NULL;

	while(*(s + sLen) != '\0') {
		sLen++;
	}

	retStr = (char *)malloc((sLen + 1) * sizeof(char));
	*(retStr + sLen) = '\0';

	retStr = convert(s, numRows);

	printf("Input: %s\n", s);
	printf("Rows: %d\n", numRows);
	printf("Output: %s\n", retStr);

	free(retStr);
	retStr = NULL;
}
