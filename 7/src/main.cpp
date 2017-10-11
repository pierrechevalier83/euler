/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that
the 6th prime is 13.

What is the 10 001st prime number?
*/

#include <boost/math/special_functions/prime.hpp>
#include <iostream>
#include <range/v3/all.hpp>

auto nth_prime(int index) { return boost::math::prime(index); }

auto one_based(int index) { return index - 1; }

bool is_prime(int n) {
  using namespace ranges::view;
  auto any_factor =
      ints(0) |
      take_while([n](auto index) { return nth_prime(index) <= sqrt(n); }) |
      transform(nth_prime) |
      filter([n](auto prime) { return (n % prime == 0); }) | take(1) |
      ranges::to_vector;
  return any_factor.empty();
}

auto next_prime(int index) {
  while (!is_prime(++index)) {
    // churn
  }
  return index;
}

int main() { std::cout << next_prime(nth_prime(one_based(10000))) << '\n'; }