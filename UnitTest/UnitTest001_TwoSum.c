#include <stdio.h>
#include <stdlib.h>

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

  for(i = numsSize - 1; i > 0; i--) {
    if(*(tmp + i) * 2 < target) {
      break;
    }

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

  *res = 0;
  *(res + 1) = 0;
  free(tmp);
  tmp = NULL;

  return res;
}

int main() {
  int nums[] = {-3, 4, 3, 90};
  int target = 0;
  int len = sizeof(nums) / sizeof(int);
  int* result = (int *)malloc(2 * sizeof(int));
 
  printf("Given nums = [");
  for(int i = 0; i < len; i++) {
    if(i == len - 1) {
      printf("%d], target = ", *(nums + i));
    }
    else {
      printf("%d, ", *(nums + i));
    }
  }
  printf("%d,\n\n", target);

  result = twoSum(nums, len, target);

  printf("Because nums[%d] + nums[%d] = %d + %d = %d,\n",
    *result, *(result + 1), *(nums + *result), *(nums + *(result + 1)), target);

  if((*result == 0) && (*(result + 1) == 0)) {
    printf("return NULL\n");
    free(result);
    result = NULL;

    return 0;
  }

  printf("return [%d, %d]\n", *result, *(result + 1));

  free(result);
  result = NULL;
  
  return 1;
}
