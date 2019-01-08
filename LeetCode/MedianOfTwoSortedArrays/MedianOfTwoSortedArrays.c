#include <stdio.h>
#include <stdlib.h>

/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int index1 = 0, index2 = 0, index = 0;
	int length = nums1Size + nums2Size;
	int* arr = malloc(sizeof(int) * (length / 2 + 1));
	while ((index1 < nums1Size || index2 < nums2Size) && index <= length / 2) {
		if (index1 < nums1Size && index2 < nums2Size) {
			arr[index++] = nums1[index1] < nums2[index2] ? nums1[index1++] : nums2[index2++];
		}
		else
		{
			arr[index++] = index1 < nums1Size ? nums1[index1++] : nums2[index2++];
		}
	}

	double res = 0;
	if (length % 2 == 0) {
		res = (double)(arr[index - 2] + arr[index - 1]) / (double)2;
	}
	else
	{
		res = arr[index - 1];
	}
	free(arr);
	return res;
}


//official answer
double findMedianSortedArrays2(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int m = nums1Size;
	int n = nums2Size;
	int* arr1 = nums1;
	int* arr2 = nums2;
	if (m > n) {
		int* tmp_p = arr1;
		arr1 = arr2;
		arr2 = tmp_p;
		
		int tmp = m;
		m = n;
		n = tmp;
	}
	int imin = 0, imax = m, halfLen = (m + n + 1) / 2;
	while (imin <= imax)
	{
		int i = (imin + imax) / 2;
		int j = halfLen - i;
		if (i < imax && arr2[j - 1] > arr1[i]) {
			imin = i + 1;
		}
		else if (i > imin && arr1[i - 1] > arr2[j]) {
			imax = i - 1;
		}
		else
		{
			int maxLeft = 0;
			if (i == 0) {
				maxLeft = arr2[j - 1];
			}
			else if (j == 0) {
				maxLeft = arr1[i - 1];
			}
			else
			{
				maxLeft = arr1[i - 1] > arr2[j - 1] ? arr1[i - 1] : arr2[j - 1];
			}
			if ((m + n) % 2 == 1) {
				return maxLeft;
			}
			
			int minRight = 0;
			if (i == m) { 
				minRight = arr2[j]; 
			}
			else if (j == n) {
				minRight = arr1[i]; 
			}
			else { 
				minRight = arr1[i] < arr2[j] ? arr1[i] : arr2[j];
			}

			return (maxLeft + minRight) / 2.0;
		}
	}
	return 0.0;
}


int main() {
	int arr1[] = {3, 4};
	int arr2[] = {1, 2};
	double d = findMedianSortedArrays2(arr1, 2, arr2, 2);
	printf("%f\n", d);
	return 0;
}