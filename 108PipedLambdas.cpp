//
// Created by Adrian Dediu on 04/05/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ranges>

int main() {
    std::vector<int> nums{3, 7, 2, 8, 1, 9, 4, 6, 5};

    auto result = nums | std::views::filter([](int num) {
        return num > 5;
    }) | std::views::transform([](int num) {
        return num * 2;
    }) | std::views::reverse | std::views::take(3);

    for (const auto &val: result) {
        std::cout << val << " ";
    }
    std::cout << std::endl<<"----------------";

    nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    return 0;
}
