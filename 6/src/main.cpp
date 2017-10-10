/*
The sum of the squares of the first ten natural numbers is,
1^2 + 2^2 + ... + 10^2 = 385

The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)^2 = 55^2 = 3025

Hence the difference between the sum of the squares of the first ten natural
numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred
natural numbers and the square of the sum.
*/

#include <range/v3/view.hpp>
#include <iostream>

int64_t square(int x) {
	return x * x;
}

using namespace ranges;
int64_t sum_of_squares(int up_to) {
	return accumulate(view::ints(1, up_to + 1) | view::transform(square), 0);
}

int64_t square_of_sum(int up_to) {
	return square(accumulate(view::ints(1, up_to + 1), 0));
}

int64_t difference(int64_t up_to) {
	return abs(sum_of_squares(up_to) - square_of_sum(up_to));
}

int main() {
	std::cout << difference(100) << '\n';
}