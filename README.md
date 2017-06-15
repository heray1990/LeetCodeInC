# LeetCodeInC

C stuffs in leetcode.com

## Table of Contents

- [#1 Two Sum](https://github.com/heray1990/LeetCodeInC#1-two-sum)
- [#2 Add Two Numbers](https://github.com/heray1990/LeetCodeInC#2-add-two-numbers)
- [#3 Longest Substring Without Repeating Characters](https://github.com/heray1990/LeetCodeInC#3-longest-substring-without-repeating-characters)
- [#4 Median of Two Sorted Arrays](https://github.com/heray1990/LeetCodeInC#4-median-of-two-sorted-arrays)
- [#5 Longest Palindromic Substring](https://github.com/heray1990/LeetCodeInC#5-longest-palindromic-substring)
- [#6 ZigZag Conversion](https://github.com/heray1990/LeetCodeInC#6-zigzag-conversion)
- [#7 Reverse Integer](https://github.com/heray1990/LeetCodeInC#7-reverse-integer)
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

## #6 ZigZag Conversion

**Link in leetcode.com:**

[https://leetcode.com/problems/zigzag-conversion/#/description](https://leetcode.com/problems/zigzag-conversion/#/description)

**Problem description:**

The string `"PAYPALISHIRING"` is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

```
P   A   H   N
A P L S I I G
Y   I   R
```

And then read line by line: `"PAHNAPLSIIGYIR"`

Write the code that will take a string and make this conversion given a number of rows:

```
string convert(string text, int nRows);
```

`convert("PAYPALISHIRING", 3)` should return `"PAHNAPLSIIGYIR"`.

**Source code:**

[https://github.com/heray1990/LeetCodeInC/blob/master/Solution/006_ZigZagConversion.c](https://github.com/heray1990/LeetCodeInC/blob/master/Solution/006_ZigZagConversion.c)

## #7 Reverse Integer

**Link in leetcode.com:**

[https://leetcode.com/problems/reverse-integer/#/description](https://leetcode.com/problems/reverse-integer/#/description)

**Problem description:**

Reverse digits of an integer.

**Example1:** x = 123, return 321

**Example2:** x = -123, return -321

**Have you thought about this?**

Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

**Note:**

The input is assumed to be a 32-bit signed integer. Your function should **return 0 when the reversed integer overflows**.

**Source code:**

[https://github.com/heray1990/LeetCodeInC/blob/master/Solution/007_ReverseInteger.c](https://github.com/heray1990/LeetCodeInC/blob/master/Solution/007_ReverseInteger.c)

## #8 String to Integer (atoi)

**Link in leetcode.com:**

[https://leetcode.com/problems/string-to-integer-atoi/#/description](https://leetcode.com/problems/string-to-integer-atoi/#/description)

**Problem description:**

Implement `atoi` to convert a string to an integer.

**Hint:** Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

**Notes:** It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

**Update (2015-02-10):**

The signature of the `C++` function had been updated. If you still see your function signature accepts a `const char *` argument, please click the reload button  to reset your code definition.

**Requirements for atoi:**

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

**Source code:**

[https://github.com/heray1990/LeetCodeInC/blob/master/Solution/008_String2Integer.c](https://github.com/heray1990/LeetCodeInC/blob/master/Solution/008_String2Integer.c)

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