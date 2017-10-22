/*
A pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a^2 + b^2 = c^2

For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2

There exists exactly one Pythagorean triplet for which a + b + c = 1000
Find the product abc
*/

#include <iostream>
#include <range/v3/all.hpp>
#include <tuple>

struct Triplet {
  int a;
  int b;
  int c;
};

using namespace ranges::view;
template <int Sum>
auto triplets_adding_up_to = for_each(ints(1, Sum - 2), [](int x) {
  return for_each(ints(1, Sum - x), [=](int y) {
    auto z = Sum - (x + y);
    return ranges::yield(Triplet{x, y, z});
  });
});

bool is_pythagorean(Triplet t) { return t.a * t.a + t.b * t.b == t.c * t.c; }

int product(Triplet t) { return t.a * t.b * t.c; }

int main() {
  auto the_one = (triplets_adding_up_to<1000> | filter(is_pythagorean) |
                  take(1) | ranges::to_vector)
                     .front();
  std::cout << product(the_one) << '\n';
}