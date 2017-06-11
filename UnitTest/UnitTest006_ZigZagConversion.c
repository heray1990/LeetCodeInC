#include <stdio.h>
#include <stdlib.h>

char* convert(char* s, int numRows) {
	int i = 0, j = 0;
	int sLen = 0;
	char* retStr = NULL;

	while(*(s + sLen) != '\0') {
		sLen++;
	}

	if((sLen <= numRows) || (numRows <= 1)) {
		return s;
	}

	while((numRows - 1) * j <= sLen) {
		for(i = 0; i < (numRows - 1); i++) {
			if((i % 2) == 0) {
				*(retStr + (numRows - 1) * j + i) = *(s + )
			}
			else {

			}
			*(retStr + i + (numRows - 1) * j) = *(s + );
		}
		j++;
	}
}

int main() {

}
