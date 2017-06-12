#include <stdio.h>

int reverse(int x) {
	// 32-bit signed integer: [-2147483648, 2147483647]
	// 2 ^ 32 / 2 = 2147483648
	const int max = 2147483647;
	const int min = -2147483648;
	int i = 0;
	int len = 0;

	if((x > -10) && (x < 10)) {
		return x;
	}

	i = x;
	do {
		len++;
		i = i / 10;
	} while(i != 0);

	if(len > 10) {
		// Overflow
		return 0;
	}
	else if(len == 10) {
		for(i = 0; i <= 10; i++) {
			if(x >= 0) {
				if(x % 10 > )
			}
		}
	}
}

int main() {


}
