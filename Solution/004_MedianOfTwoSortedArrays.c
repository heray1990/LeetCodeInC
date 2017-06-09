double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int i = 0, j = 0, k = 0;
	int nums3Size = nums1Size + nums2Size;
	int* nums3 = (int*)malloc(nums3Size * sizeof(int));
	int medianIdx = 0;
	double median = 0.0;

	// Merge nums1 and nums2 to nums3.
	while((i < nums1Size) && (j < nums2Size)) {
		if(*(nums1 + i) < *(nums2 + j)) {
			*(nums3 + k) = *(nums1 + i);
			i++;
			k++;
		}
		else {
			*(nums3 + k) = *(nums2 + j);
			j++;
			k++;
		}
	}

	while(i < nums1Size) {
		*(nums3 + k) = *(nums1 + i);
		i++;
		k++;
	}

	while(j < nums2Size) {
		*(nums3 + k) = *(nums2 + j);
		j++;
		k++;
	}

	if(nums3Size % 2 == 0) {
		medianIdx = nums3Size / 2;
		median = ((double)*(nums3 + medianIdx - 1) + (double)*(nums3 + medianIdx)) / 2;
	}
	else {
		medianIdx = nums3Size / 2;
		median = *(nums3 + medianIdx);
	}

	free(nums3);
	nums3 = NULL;

	return median;
}
