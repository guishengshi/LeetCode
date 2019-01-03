#include <stdio.h>
#include <malloc.h>
#include <time.h>

/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

//±©Á¦Ñ­»·
int* twoSum(int* nums, int numsSize, int target) {
	int * res = malloc(2 * sizeof(int));
	int diff = 0;
	for (int i = 0; i < numsSize - 1; i++) {
		res[0] = i;
		diff = target - nums[i];
		for (int j = i + 1; j < numsSize; j++) {
			if (nums[j] == diff) {
				res[1] = j;
				return res;
			}
		}
	}
	return res;
}


//two hash
int* twoSumByTwoHash(int* nums, int numsSize, int target) {
	int i, max, min;
	max = min = nums[0];
	for (i = 1; i < numsSize; i++) {
		if (nums[i] > max) max = nums[i];
		if (nums[i] < min) min = nums[i];
	}

	int *map = (int*)calloc((max - min + 1), sizeof(int));
	int *res = (int*)malloc(sizeof(int) * 2);

	for (i = 0; i < numsSize; ++i) {
		map[nums[i] - min] = i + 1;
	}

	for (i = 0; i < numsSize; ++i) {
		int lookfornum = target - nums[i];
		if (lookfornum < min || lookfornum > max) continue;
		int dis = lookfornum - min;
		if (map[dis] && map[dis] - 1 != i) {
			res[0] = i;
			res[1] = map[dis] - 1;
			break;
		}
	}
	free(map);
	return res;
}

//one hash 
int* twoSumByOneHash(int* nums, int numsSize, int target) {
	int i, max, min;
	max = min = nums[0];
	for (i = 1; i < numsSize; i++) {
		if (nums[i] > max) max = nums[i];
		if (nums[i] < min) min = nums[i];
	}

	int *map = (int*)calloc((max - min + 1), sizeof(int));
	int *res = (int*)malloc(sizeof(int) * 2);

	for (i = 0; i < numsSize; ++i) {
		int lookfornum = target - nums[i];
		if (lookfornum < min || lookfornum > max) continue;
		int dis = lookfornum - min;
		if (map[dis]) {
			res[0] = i;
			res[1] = map[dis] - 1;
			break;
		}
		map[nums[i] - min] = i + 1;
	}
	free(map);
	return res;
}



int main() {
	int nums[] = { 3, 2, 4 };
	time_t start, stop;
	start = clock();
	int* p_index_array = twoSumByTwoHash(nums, 3, 6);
	stop = clock();
	printf("time : %lld\n", stop - start);
	if (p_index_array) {
		for (int i = 0; i < 2; i++) {
			printf("index : %d value : %d ", p_index_array[i], nums[p_index_array[i]]);
		}
		free(p_index_array);
	}
}