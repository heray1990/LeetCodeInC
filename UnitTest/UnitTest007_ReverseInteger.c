#include <stdio.h>
#include <stdlib.h>

int reverse(int x) {
	// 32-bit signed integer: [-2147483648, 2147483647]
	// 2 ^ 32 / 2 = 2147483648
	const int max = 2147483647;
	const int min = -2147483648;
	int i = 0, j = 0;
	int tmp1 = 0, tmp2 = 0, divisor = 0;
	int len = 0, maxLen = 0;
	int res = 0;

	if((x > -10) && (x < 10)) {
		return x;
	}

	tmp1 = x;
	do {
		len++;
		tmp1 = tmp1 / 10;
	} while(tmp1 != 0);

	tmp1 = max;
	do {
		maxLen++;
		tmp1 = tmp1 / 10;
	} while(tmp1 != 0);

	if(len > maxLen) {
		// Overflow
		return 0;
	}
	else if(len == maxLen) {
		if(x >= 0) {
			tmp1 = x;
			tmp2 = max;
		}
		else {
			tmp1 = x;
			tmp2 = min;
		}

		for(i = maxLen - 1; i >= 0; i--) {
			divisor = 1;
			for(j = 0; j < i; j++) {
				divisor *= 10;
			}

			//printf("tmp1 = %d, tmp2 = %d\n", tmp1, tmp2);
			if(abs(tmp1 % 10) > abs(tmp2 / divisor)) {
				// Overflow
				return 0;
			}
			else {
				break;
			}
			tmp1 = tmp1 / 10;
			tmp2 = tmp2 % divisor;
		}
	}

	tmp1 = x;
	tmp2 = 1;
	for(i = 0; i < len - 1; i++) {
		tmp2 *= 10;
	}

	for(i = len - 1; i >= 0; i--) {
		divisor = 1;
		for(j = 0; j < i; j++) {
			divisor *= 10;
		}
		res = res + (tmp1 / divisor) * (tmp2 / divisor);
		tmp1 = tmp1 % divisor;
	}

	return res;
}

int main() {
	int x = 123;
	int res = 0;
	
	res = reverse(x);
	printf("Input: %d\n", x);
	printf("Output: %d\n", res);
}
