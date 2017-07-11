#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int reverse(int x) {
	if(x > INT_MAX || x < INT_MIN + 1)
		return 0;

	if(x == 0)
		return 0;

	if(x < 0)
		return (-1) * reverse((-1) * x);

	int num[20] = {0};
	int top = 0, end = 0;
	long long temp = 0;

	for(temp = x; temp > 0;) {
		num[top] = temp % 10;
		top++;
		temp = temp / 10;
	}

	top--;

	for(temp = 0, end = 0; end <= top;) {
		temp = temp * 10 + num[end];

		if(temp >= INT_MAX)
			return 0;

		end++;
	}

	return temp;
}

int main() {
	//int x = 1563847412;
	int x = -1000000002;
	int res = 0;
	
	res = reverse(x);
	printf("Input: %d\n", x);
	printf("Output: %d\n", res);
}
