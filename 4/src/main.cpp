/*
A palindromic number reads the same both ways. The largest palindrome made from
the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/
#include <boost/algorithm/is_palindrome.hpp>
#include <iostream>
#include <range/v3/view.hpp>
#include <ipow.h>

template <int order> auto max_n_digit_number() { return ipow(10, order) - 1; }
template <int order> auto min_n_digit_number() { return ipow(10, order - 1); }
template <int order> bool is_n_digit_number(int n) {
  return n <= max_n_digit_number<order>() && n >= min_n_digit_number<order>();
}

bool is_palindrome(int n) {
  return boost::algorithm::is_palindrome(std::to_string(n));
}

template <int order> bool is_product_of_2_n_digits_numbers(int n) {
  auto first_valid_decomposition =
      ranges::view::ints(min_n_digit_number<order>(),
                         max_n_digit_number<order>() + 1) |
      ranges::view::reverse | ranges::view::filter([&n](auto factor) {
        if (n % factor == 0) {
          if (is_n_digit_number<order>(n / factor)) {
            return true;
          }
        };
        return false;
      }) |
      ranges::view::take(1) | ranges::to_vector;
  return !first_valid_decomposition.empty();
}

template <int order> auto largest_palindrome_product() {
  auto max_product = ipow(max_n_digit_number<order>(), 2);
  auto any = ranges::view::ints(0, max_product + 1) | ranges::view::reverse |
             ranges::view::filter(is_palindrome) |
             ranges::view::filter(is_product_of_2_n_digits_numbers<order>) |
             ranges::view::take(1) | ranges::to_vector;
  return any.front();
}

int main() { std::cout << largest_palindrome_product<3>() << std::endl; }