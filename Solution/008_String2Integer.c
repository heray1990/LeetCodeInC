int myAtoi(char* str) {
	const int maxLen = 10;
	int len = strlen(str);
	int numCnt = 0, sign = 1;
	int i = 0, j = 0;
	int flag = 0;
	int res = 0;

	// Discard non-numerical characters of str.
	// ASCII: '0' => 48, '9' => 57
	while(str[i] != '\0') {
		if(((str[i] >= '0') && (str[i] <= '9')) 
			|| (((str[i] == '-') || (str[i] == '+')) && (flag == 0))) {
			if(str[i] == '-') {
				sign = -1;
				i++;
				flag = 1;
				continue;
			}
			if(str[i] == '+') {
				sign = 1;
				i++;
				flag = 1;
				continue;
			}

			if(!((numCnt == 0) && (str[i] == '0'))) {
				numCnt++;
				if(numCnt == maxLen) {
					if(sign == 1) {
						if((res > INT_MAX / 10) ||
							(res == INT_MAX / 10) 
							&& (sign * (str[i] - 48) > INT_MAX % 10)) {
							// Overflow
							return INT_MAX;
						}
					}
					if(sign == -1) {
						if((res < INT_MIN / 10) ||
							(res == INT_MIN / 10) 
							&& (sign * (str[i] - 48) < INT_MIN % 10)) {
							// Overflow
							return INT_MIN;
						}
					}
				}
				if(numCnt > maxLen) {
					// Overflow
					if(sign == 1) {
					    return INT_MAX;
					}
					
					if(sign == -1) {
					    return INT_MIN;
					}
				}
				res = res * 10 + sign * (str[i] - 48);
			}
		}
		else {
			if((numCnt > 0) || (flag == 1)
				|| ((numCnt == 0) && (str[i] != ' '))) {
				break;
			}
		}

		i++;
	}

	return res;
}
