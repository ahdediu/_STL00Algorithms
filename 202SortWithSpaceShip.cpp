#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> nums = {3, 6, 2, 9, 1, 7, 5, 8};
    int count = std::count_if(nums.begin(), nums.end(), [](int num) {
        return num > 5;
    });
    std::cout << "Number of elements greater than 5: " << count << std::endl;
    return 0;
}
