# LeetCodeInC

C stuffs in leetcode.com

## Table of Contents

- [#1 Two Sum](https://github.com/heray1990/LeetCodeInC#1-two-sum)
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

## #9 Palindrome Number

**Link in leetcode.com:**

[https://leetcode.com/problems/palindrome-number/](https://leetcode.com/problems/palindrome-number/)

**Problem description:**

Determine whether an integer is a palindrome. Do this without extra space.

**Source code:**

[https://github.com/heray1990/LeetCodeInC/blob/master/Solution/009_PalindromeNumber.c](https://github.com/heray1990/LeetCodeInC/blob/master/Solution/009_PalindromeNumber.c)

**Note:**

- There is not a "bool" type in C.
- "^" computes the bitwise XOR in C. Thus "10^4" can NOT get 10000(fourth power of 10) in C.
- [This modification](https://github.com/heray1990/LeetCodeInC/commit/f0c8107e3329eae74d9d2518adcb676ce3fd681d) shows two different ways to caculate the digit number of an integer number. Note that one of them fails to caculate the digit number of 1410110141.

**Example:**

![](https://github.com/heray1990/LeetCodeInC/raw/master/Resources/009_PalindromeNumber.gif)