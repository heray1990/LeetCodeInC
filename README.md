# LeetCodeInC

C stuffs in leetcode.com

## Table of Contents

- [#1 Two Sum](https://github.com/heray1990/LeetCodeInC#1-two-sum)
- [#2 Add Two Numbers](https://github.com/heray1990/LeetCodeInC#2-add-two-numbers)
- [#3 Longest Substring Without Repeating Characters](https://github.com/heray1990/LeetCodeInC#3-longest-substring-without-repeating-characters)
- [#4 Median of Two Sorted Arrays](https://github.com/heray1990/LeetCodeInC#4-median-of-two-sorted-arrays)
- [#5 Longest Palindromic Substring](https://github.com/heray1990/LeetCodeInC#5-longest-palindromic-substring)
- [#9 Palindrome Number](https://github.com/heray1990/LeetCodeInC#9-palindrome-number)

## #1 Two Sum

**Link in leetcode.com:**

[https://leetcode.com/problems/two-sum/#/description](https://leetcode.com/problems/two-sum/#/description)

**Problem description:**

Given an array of integers, return **indices** of the two numbers such that they add up to a specific target.

You may assume that each input would have ***exactly*** one solution, and you may not use the *same* element twice.

**Example:**

```
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
```

**Source code:**

[https://github.com/heray1990/LeetCodeInC/blob/master/Solution/001_TwoSum.c](https://github.com/heray1990/LeetCodeInC/blob/master/Solution/001_TwoSum.c)

## #2 Add Two Numbers

**Link in leetcode.com:**

[https://leetcode.com/problems/add-two-numbers/#/description](https://leetcode.com/problems/add-two-numbers/#/description)

**Problem description:**

You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

**Input:** (2 -> 4 -> 3) + (5 -> 6 -> 4)

**Output:** 7 -> 0 -> 8

**Source code:**

[https://github.com/heray1990/LeetCodeInC/blob/master/Solution/002_AddTwoNumbers.c](https://github.com/heray1990/LeetCodeInC/blob/master/Solution/002_AddTwoNumbers.c)

## #3 Longest Substring Without Repeating Characters

**Link in leetcode.com:**

[https://leetcode.com/problems/longest-substring-without-repeating-characters/#/description](https://leetcode.com/problems/longest-substring-without-repeating-characters/#/description)

**Problem description:**

Given a string, find the length of the **longest substring** without repeating characters.

**Examples:**

Given `"abcabcbb"`, the answer is `"abc"`, which the length is 3.

Given `"bbbbb"`, the answer is `"b"`, with the length of 1.

Given `"pwwkew"`, the answer is `"wke"`, with the length of 3. Note that the answer must be a **substring**, `"pwke"` is a *subsequence* and not a substring.

**Source code:**

[https://github.com/heray1990/LeetCodeInC/blob/master/Solution/003_LongestSubstring.c](https://github.com/heray1990/LeetCodeInC/blob/master/Solution/003_LongestSubstring.c)

![](https://github.com/heray1990/LeetCodeInC/raw/master/Resources/003_LongestSubstring.gif)

## #4 Median of Two Sorted Arrays

There are two sorted arrays **nums1** and **nums2** of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

**Example 1:**

```
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
```

**Example 2:**

```
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
```

**Source code:**

[https://github.com/heray1990/LeetCodeInC/blob/master/Solution/004_MedianOfTwoSortedArrays.c](https://github.com/heray1990/LeetCodeInC/blob/master/Solution/004_MedianOfTwoSortedArrays.c)

## #5 Longest Palindromic Substring

Given a string **s**, find the longest palindromic substring in **s**. You may assume that the maximum length of **s** is 1000.

**Example:**

```
Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
```

**Example:**

```
Input: "cbbd"

Output: "bb"
```

**Source code:**

[https://github.com/heray1990/LeetCodeInC/blob/master/Solution/005_LongestPalindromicSubstring.c](https://github.com/heray1990/LeetCodeInC/blob/master/Solution/005_LongestPalindromicSubstring.c)

![](https://github.com/heray1990/LeetCodeInC/raw/master/Resources/005_LongestPalindromicSubstring.gif)

## #9 Palindrome Number

**Link in leetcode.com:**

[https://leetcode.com/problems/palindrome-number/](https://leetcode.com/problems/palindrome-number/)

**Problem description:**

Determine whether an integer is a palindrome. Do this without extra space.

**Source code:**

[https://github.com/heray1990/LeetCodeInC/blob/master/Solution/009_PalindromeNumber.c](https://github.com/heray1990/LeetCodeInC/blob/master/Solution/009_PalindromeNumber.c)

![](https://github.com/heray1990/LeetCodeInC/raw/master/Resources/009_PalindromeNumber.gif)

**Note:**

- There is not a "bool" type in C.
- "^" computes the bitwise XOR in C. Thus "10^4" can NOT get 10000(fourth power of 10) in C.
- [This modification](https://github.com/heray1990/LeetCodeInC/commit/f0c8107e3329eae74d9d2518adcb676ce3fd681d) shows two different ways to caculate the digit number of an integer number. Note that one of them fails to caculate the digit number of 1410110141.