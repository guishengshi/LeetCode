#include <stdio.h>

/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

int lengthOfLongestSubstring(char* s) {
	int length = strlen(s);
	if (!length) {
		return 0;
	}
	int arr[256] = { 0 };		//str hash
	for (int i = 0; i < 256; i++) {
		arr[i] = -1;
	}
	int maxLen = 0;
	int pre = -1;
	int cur = -1;
	for (int i = 0; i < length; i++) {
		if (arr[s[i]] < pre) {
			maxLen = i - cur > maxLen ? i - cur : maxLen;
			cur = i;
		}
		else
		{
			maxLen = i - arr[s[i]] > maxLen ? i - arr[s[i]] : maxLen;
			pre = arr[s[i]];
			cur = i;
		}
		arr[s[i]] = i;
		maxLen = i - pre > maxLen ? i - pre : maxLen;
	}
	return maxLen;
}

int lengthOfLongestSubstring2(char* s) {
	int length = strlen(s);
	if (!length) {
		return 0;
	}
	int arr[256] = { 0 };		//str hash
	for (int i = 0; i < 256; i++) {
		arr[i] = -1;
	}
	int maxLen = 0;
	int start = -1;
	for (int i = 0; i < length; i++)
	{
		if (arr[s[i]] > start) {
			start = arr[s[i]];
		}
		arr[s[i]] = i;
		maxLen = maxLen > i - start ? maxLen : i - start;
	}
	return maxLen;
}

int main() {
	int length = lengthOfLongestSubstring2("ohomm");
	printf("%d\n", length);
	return 0;
}