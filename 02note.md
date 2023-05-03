### New things comparing to old style programming

```objective-c++
    vector<int> coll = {2, 5, 4, 1, 6, 3};
    // find and print minimum and maximum elements
    auto minpos = min_element(coll.cbegin(), coll.cend());
    cout << "min: " << *minpos << endl;
    //...
    sort(coll.begin(), coll.end());
    for (auto elem: coll) {
        cout << elem << ' ';
    }
```
* Initializer list can be used to initialize the vector.
* Members cbegin() and cend() are provided, so instead of begin() and end(). In the old style we can still use const_iterators.
* In the old style we cannot use auto, we have to declare the iterators explicitly.
* we can use range-based for loops, but also iterators to output each element.

**begin()** returns an _iterator to beginning_ while **cbegin()** returns a _const_iterator to beginning_. 

The basic difference between these two iterators: 
* begin() lets you change the value of the object it is pointing to.
* const_iterator will not let you change the value of the object.