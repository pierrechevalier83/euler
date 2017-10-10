// A little utility function analogous to pow but for ints
// For integral types only:

auto ipow(int base, int exp) {
  int result = 1;
  while (exp) {
    if (exp & 1) {
      result *= base;
    }
    exp >>= 1;
    base *= base;
  }
  return result;
}
