/*
2520 is the smallest number that can be divided by each of the numbers from 1 to
10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the
numbers from 1 to 20?
*/

#include <boost/math/special_functions/prime.hpp>
#include <iostream>
#include <range/v3/all.hpp>

using namespace ranges::view;

using Factorised = std::vector<int>;

int nth_prime(int n) {
  return static_cast<int>(boost::math::prime(static_cast<unsigned>(n)));
}

Factorised factorise(int n) {
  return ints(0) |
         take_while([n](auto index) { return nth_prime(index) <= n; }) |
         transform(nth_prime) | transform([&n](auto prime) {
           Factorised result;
           while (n % prime == 0) {
             n /= prime;
             result.push_back(prime);
           }
           return result;
         }) |
         ranges::action::join | ranges::to_vector;
}

auto smallest_multiple_of_ints_until(int n) {
  Factorised result;
  auto factorised_candidates =
      ints(1, n + 1) | reverse | transform(factorise) | ranges::to_vector;
  for (const auto &candidate : factorised_candidates) {
    result = set_union(result, candidate) | ranges::to_vector;
  }
  return ranges::accumulate(result, 1, std::multiplies<int>());
}

int main() { std::cout << smallest_multiple_of_ints_until(20) << '\n'; }