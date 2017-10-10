/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/
#include <boost/math/special_functions/prime.hpp>
#include <cstdint>
#include <iostream>
#include <optional>
#include <range/v3/view.hpp>

auto prime(int index) {
  return boost::math::prime(static_cast<unsigned>(index));
}

auto largest_prime_factor(int64_t n) {
  auto largest = 1;
  auto all = ranges::view::ints(0) |
             ranges::view::take(boost::math::max_prime) |
             ranges::view::transform(prime) |
             ranges::view::filter([&largest, &n](auto prime) {
               if (n % prime == 0) {
                 largest = prime;
                 n /= prime;
                 return true;
               };
               return false;
             }) |
             ranges::view::take_while([n](auto prime) { return prime < n; }) |
             ranges::to_vector;
  return largest < n ? std::nullopt : std::make_optional(largest);
}

int main() { std::cout << *largest_prime_factor(600851475143) << '\n'; }