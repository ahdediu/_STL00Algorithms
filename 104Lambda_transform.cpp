//
// Created by Adrian Dediu on 03/05/2023.
//
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>


void print_ordinals(std::vector<std::size_t> const &ordinals) {
    std::cout << "ordinals: ";
    for (std::size_t ord: ordinals)
        std::cout << std::setw(3) << ord << ' ';
    std::cout << '\n';
}

int main() {
    std::string s{"hello"};
    std::transform(s.cbegin(), s.cend(),
                   s.begin(), // write to the same location
                   [](unsigned char c) { return std::toupper(c); });
    std::cout << "s = " << std::quoted(s) << '\n';

    // achieving the same with std::for_each (see Notes above)
    std::string g{"hello"};
    std::for_each(g.begin(), g.end(), [](char &c) // modify in-place
    {
        c = std::toupper(static_cast<unsigned char>(c));
    });
    std::cout << "g = " << std::quoted(g) << '\n';

    std::vector<std::size_t> ordinals;
    std::transform(s.cbegin(), s.cend(), std::back_inserter(ordinals),
                   [](unsigned char c) { return c; });

    print_ordinals(ordinals);

    std::transform(ordinals.cbegin(), ordinals.cend(), ordinals.cbegin(),
                   ordinals.begin(), std::plus<>{});

    print_ordinals(ordinals);
    std::cout << "===============\n";
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // filter out odd numbers using lambda expression
    auto is_even = [](int n) { return n % 2 == 0; };
    numbers.erase(std::remove_if(numbers.begin(), numbers.end(), is_even), numbers.end());

    // print out the filtered result
    for (auto n: numbers) {
        std::cout << n << " ";
    }
    /*
     * Unary transform is the basic transformation algorithm.
     * It takes a range of inputs, applies a given operation on each element and
     * puts the results into an output range.
     */
    std::cout << "\n=====Unary Transform==========\n";
    auto values = std::vector<int>{1, 2, 3, 4, 5};
    auto doubleValues = std::vector<int>(values.size());
    std::transform(values.begin(), values.end(), doubleValues.begin(), [](int number) { return 2 * number; });
/*
 * Solution 2
auto doubleValues = std::vector<int>{};
std::transform(values.begin(), values.end(), std::back_inserter(doubleValues), [](int number) {return 2*number;});

 */
    std::for_each(doubleValues.begin(), doubleValues.end(), [](int number) { std::cout << number << "\n"; });

    std::cout << "\n====Binary Transform===========\n";
/*
 * Binary transform
It means that the last parameter of the constructor will be a lambda that takes two inputs instead of one.
The second parameter comes from another input iterator!
The first input range is defined by two iterators (begin and end), the second one is defined by only it’s start point.
What happens if the second range contains fewer elements? Nasty things!
 As a rule, keep in mind that always the first range should be the shorter/smaller one.

 */

    auto otherValues = std::vector<float>{10.1f, 20.2f, 30.3f, 40.4f, 50.5f};
    auto results = std::vector<std::string>{};
    std::transform(values.begin(), values.end(), otherValues.begin(), std::back_inserter(results),
                   [](int number, float otherNumber) { return std::to_string(number + otherNumber); });


    std::cout << results[0];
    std::for_each(results.begin() + 1, results.end(), [](const std::string &number) { std::cout << " - " << number; });
    return 0;
}