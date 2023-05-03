//
// Created by Adrian Dediu on 30/04/2023.
//
#include <iostream>
int main(){
    int x=0;
    int y=42;
    auto qqq = [x, &y] {
        std::cout << "inside Lambda x: " << x << " y: " << y << std::endl;
        ++y; // OK
    };
    x = y = 77;
    qqq();
    qqq();
    std::cout << "final y: " << y << std::endl;
    return 0;
}