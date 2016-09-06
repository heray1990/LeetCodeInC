bool isPalindrome(int x) {
  int digitCnt = 1;
  int n;

  if (x < 0)
    return false;

  if (x >= 0 && x < 10)
    return true;

  do {
    digitCnt++;
  } while (x / (10^digitCnt) != 0)

  for (n = 1; n <= (digitCnt / 2); n++) {
    if (x % (10^digitCnt) != x / (10^(digitCnt - n)))
      return false;
  }

  return true;
}
