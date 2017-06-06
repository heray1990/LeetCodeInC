/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
  int i, j, key;
  int* res = (int *)malloc(2 * sizeof(int));
  int* tmp = (int *)malloc(numsSize * sizeof(int));

  for(i = 0; i < numsSize; i++) {
    *(tmp + i) = *(nums + i);
  }

  // Sorting tmp[] by using Insertion Sort.
  for(j = 1; j < numsSize; j++) {
    key = *(tmp +j);
    i = j - 1;

    while(i >=0 && *(tmp + i) > key) {
      *(tmp + i + 1) = *(tmp + i);
      i--;
    }
    *(tmp + i + 1) = key;
  }

  for(i = numsSize - 1; i >= 0; i--) {
    if(*(tmp + i) * 2 < target) {
      break;
    }

    if((*(tmp + i) <= target) && (*(tmp + i) * 2 >= target)) {
      for(j = 0; j < i; j++) {
        if(*(tmp + i) + *(tmp + j) > target) {
            break;
        }

        if(*(tmp + i) + *(tmp + j) == target) {
          int m = 0;
          int n = 0;

          for(m = 0; m < numsSize; m++) {
            if((*(tmp + i) == *(nums + m)) || (*(tmp + j) == *(nums + m))) {
              if(n == 0) {
                *res = m;
                n++;
              }
              else {
                *(res + 1) = m;
              }
            }
          }
          free(tmp);
          tmp = NULL;
          return res;
        }
      }
    }
  }

  *res = 0;
  *(res + 1) = 0;
  free(tmp);
  tmp = NULL;
  return res;
}
