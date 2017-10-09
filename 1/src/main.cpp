/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get
3, 5, 6 and 9. The sum of these multiples is 23. Find the sum of all the
multiples of 3 or 5 below 1000.
*/

#include <iostream>
#include <range/v3/view.hpp>

template <int N> bool multiple(int n) { return n % N == 0; }

bool multiple_of_3_or_5(int n) { return multiple<3>(n) || multiple<5>(n); }

int sum_of_multiples(int up_to) {
  return ranges::accumulate(ranges::view::ints(0) | ranges::view::take(up_to) |
                                ranges::view::filter(multiple_of_3_or_5),
                            0);
}

int main() { std::cout << sum_of_multiples(1000) << '\n'; }
