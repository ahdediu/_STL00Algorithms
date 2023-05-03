### Lambdas

#### Syntax of Lambdas
(page 28)

A lambda is a definition of functionality that can be defined inside statements and expressions. Thus,
you can use a lambda as an inline function.
The minimal lambda function has no parameters and simply does something. For example:

```c++
[] {
std::cout << "hello lambda" << std::endl;
}
```
You can call it directly:
```c++
[] {
std::cout << "hello lambda" << std::endl;
} (); // prints ‘‘hello lambda’’
```
or pass it to objects to get called:
```c++
auto lf = [] {
std::cout << "hello lambda" << std::endl;
};
...
lf(); // prints ‘‘hello lambda’’
```
As you can see, a lambda is always introduced by a so-called lambda introducer: brackets within
which you can specify a so-called capture to access nonstatic outside objects inside the lambda.
When there is no need to have access to outside data, the brackets are just empty, as is the case here.
Static objects such as std::cout can be used.

Between the lambda introducer and the lambda body, you can specify parameters, mutable, an
exception specification, attribute specifiers, and the return type. All of them are optional, but if one
of them occurs, the parentheses for the parameters are mandatory. Thus, the syntax of a lambda is
either


[...] {...}

or

[...] (...) mutable(optional) constexpr(optional) throwSpec(optional) -> retType(optional) {...}

* mutable(optional) If the function object should be able to modify the variables it captures by copy, it must be defined mutable. 
* constexpr (optional) If we mark the lambda expression explicitly as constexpr, the compiler will error out if it does not satisfy the criteria of constexpr functions. The advantage of constexpr functions and lambda expressions is that the compiler can evaluate their result at compile time if they are called with compile-time constant parameters. This leads to less code in the binary later. If we do not explicitly declare the lambda expression to be constexpr, but it fits the requirements for that, it will be implicitly constexpr anyway. If we want a lambda expression to be constexpr, it helps to be explicit because the compiler will then help us by erroring out if we did it wrong.
* throwSpec(optional) This is the place to specify if the function object can throw exceptions when it's called and runs into an error case.
* retType(optional) If we want to have ultimate control over the return type, we may not want the compiler to deduce it for us automatically. In such a case, we can just write [] () -> Foo {}, which  tells the compiler that we will really always return the Foo type.

A lambda can have **parameters** specified in parentheses, just like any other function:

```c++
auto lf = [] (const std::string& s) {std::cout << s << std::endl;};
lf("hello lambda"); // prints ‘‘hello lambda’’
```
**Note**: In C++20 this is possible using the following syntax:

```objective-c++
auto lambda = []<typename T>(T t){
// do something
};
```

#### Captures (Access to Outer Scope)

Inside the lambda introducer (brackets at the beginning of a lambda), you can specify a capture to
access data of outer scope that is not passed as an argument:
* [=] means that the outer scope is passed to the lambda by value. Thus, you can read but not modify all data that was readable where the lambda was defined.
* [&] means that the outer scope is passed to the lambda by reference. Thus, you have write access to all data that was valid when the lambda was defined, provided that you had write access there.

You can also specify individually for each object that inside the lambda you have access to it by
value or by reference. So, you can limit the access and mix different kinds of access. For example,
the following statements:
```objective-c++
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
```
produce the following output:
```text
inside Lambda x: 0 y: 77
inside Lambda x: 0 y: 78
final y: 79
```
Because x gets copied by value, you are not allowed to modify it inside the lambda; calling ++x
inside the lambda would not compile. Because y is passed by reference, you have write access to it
and are affected by any value change; so calling the lambda twice increments the assigned value 77.
Instead of [x, &y], you could also have specified [=, &y] to pass y by reference and all other
objects by value.
To have a mixture of passing by value and passing by reference, you can declare the lambda as
mutable. In that case, objects are passed by value, but inside the function object defined by the
lambda, you have write access to the passed value. For example:
```objective-c++
    int id = 0;
    auto f = [id] () mutable {
        std::cout << "id: " << id << std::endl;
        ++id; // OK
    };
    id = 42;
    f();
    f();
    f();
    std::cout << id << std::endl;
```
has the following output:
```text
id: 0
id: 1
id: 2
42
```
You can consider the behavior of the lambda to be like the following function object:
```objective-c++
class {
    private:
        int id; // copy of outside id
    public:
    void operator() () {
        std::cout << "id: " << id << std::endl;
        ++id; // OK
    }
};
```
Due to mutable, operator () is defined as a nonconstant member function, which means that write
access to id is possible. So, with mutable, a lambda becomes stateful even if the state is passed by
value. Without mutable, which is the usual case, operator () becomes a constant member function
so that you only have read access to objects that were passed by value.

#### Type of Lambdas

We can use the std::function<> class template, provided by the C++ standard
library, to specify a general type for functional programming. That
class template provides the only way to specify the return type of a function returning a lambda:
```objective-c++
#include<functional>
#include<iostream>
std::function<int(int,int)> returnLambda ()
{
return [] (int x, int y) {
return x*y;
};
}
int main()
{
auto lf = returnLambda();
std::cout << lf(6,7) << std::endl;
}
```
The output of the program is (of course):
```text
42
```
#### Where we are?
Studied
* Defining functions on the run using lambda expressions
* Wrapping lambdas into std::function

Todo
* Composing functions by concatenation
* Creating complex predicates with logical conjunction
* Calling multiple functions with the same input
* Implementing transform_if using std::accumulate and lambdas
* Generating cartesian product pairs of any input at compile time