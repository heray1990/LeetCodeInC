bool isPalindrome(int x) {
	int digitCnt = 0;
	int n, i, k, resPower, remainder, quotient;

	if(x < 0)
		return false;

	if(x >= 0 && x < 10)
		return true;

	k = x;
	do {
		digitCnt++;
		k = k / 10; 
	} while(k != 0);
	printf("The digit number of %d is %d.\n", x, digitCnt);

	k = digitCnt;
	for(n = 1; n <= (digitCnt / 2); n++) {
		resPower = 1;
		for(i = 0; i < (k - 1); i++) {
			resPower *= 10;
		}
		remainder = x % 10;
		quotient = x / resPower;

		printf("Loop: %d\n", n);
		printf("The rightmost digit is %d\n", remainder);
		printf("The leftmost digit is %d\n", quotient);

		if(remainder != quotient)
			return false;

		printf("Change x from %d ", x);
		x -= resPower * quotient;
		x /= 10;
		k -= 2;
		printf("to %d.\n", x);
	}

	return true;
}
