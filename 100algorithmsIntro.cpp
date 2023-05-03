// stl/algo1.cpp
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main() {
// create vector with elements from 1 to 6 in arbitrary order
    vector<int> coll = {2, 5, 4, 1, 6, 3};
// find and print minimum and maximum elements
    auto minpos = min_element(coll.cbegin(), coll.cend());
    cout << "min: " << *minpos << endl;
    auto maxpos = max_element(coll.cbegin(), coll.cend());
    cout << "max: " << *maxpos << endl;
// sort all elements
    cout << "sorted elements: ";
    sort(coll.begin(), coll.end());
    // print all elements
    for (auto elem: coll) {
        cout << elem << ' ';
    }
    cout << endl;
// find the first element with value 3
// - no cbegin()/cend() because later we modify the elements pos3 refers to
    auto pos3 = find(coll.begin(), coll.end(), // range
                     3); // value
// reverse the order of the found element with value 3 and all following elements
    cout << "reverse from the 3rd position: ";
    reverse(pos3, coll.end());
// print all elements
    for (auto elem: coll) {
        cout << elem << ' ';
    }
    cout << endl;
}
