char* convert(char* s, int numRows) {
	int i = 0, j = 0, k = 0;
	int sLen = 0;
	int column = 0;
	int divisor = 0;
	int numTmp = 0;
	char* retStr = NULL;
	char **matrix = NULL;

	while(*(s + sLen) != '\0') {
		sLen++;
	}

	if((sLen <= numRows) || (numRows <= 1)) {
		return s;
	}

	retStr = (char*)malloc((sLen + 1) * sizeof(char));
	*(retStr + sLen) = '\0';

	divisor = numRows * 2 - 2;
	column = (numRows - 1) * (sLen / divisor);
	if((sLen % divisor) <= numRows) {
		column = column + 1;
	}
	else {
		column = column + 1 + (sLen % divisor) - numRows;
	}

	// malloc a matrix.
	matrix = (char **)malloc(numRows * sizeof(char*));
	for(i = 0; i < numRows; i++) {
		*(matrix + i) = (char *)malloc(column * sizeof(char));
	}

	// Init matrix with '\0'.
	for(i = 0; i < numRows; i++) {
		for(j = 0; j < column; j++) {
			matrix[i][j] = '\0';
		}
	}

	for(j = 0; j < column; j++) {
		for(i = 0; i < numRows; i++) {
			if(j % (numRows - 1) == 0) {
				numTmp = i + divisor * (j / (numRows - 1));
				//printf("[01]i = %d, j = %d, numTmp = %d\n", i, j, numTmp);
				if(numTmp >= sLen) {
					break;
				}
				matrix[i][j] = s[numTmp];
			}

			if(j % (numRows - 1) > 0) {
				numTmp = (numRows - 1) + j % (numRows - 1) + divisor * (j / 3); 
				if(numTmp >= sLen) {
					break;
				}

				if((i + (j % (numRows - 1))) == (numRows - 1)) {
					//printf("[02]i = %d, j = %d, numTmp = %d\n", i, j, numTmp);
					matrix[i][j] = s[numTmp];
				}
			}
		}
	}
	
	for(i = 0; i < numRows; i++) {
		for(j = 0; j < column; j++) {
			if(matrix[i][j] != '\0') {
				retStr[k] = matrix[i][j];
				k++;
			}
		}
	}

	for(i = 0; i < numRows; i++) {
		free(*(matrix + i));
		*(matrix + i) = NULL;
	}
	free(matrix);
	matrix = NULL;

	return retStr;
}
