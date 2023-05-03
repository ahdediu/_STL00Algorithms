//
// Created by Adrian Dediu on 03/05/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // filter even numbers and square them
    auto result = std::transform_reduce(numbers.begin(), numbers.end(), 0, std::plus<>(),
                                        [](int num) { return num % 2 == 0 ? num * num : 0; });

    std::cout << result << std::endl; // output: 220
    return 0;
}
