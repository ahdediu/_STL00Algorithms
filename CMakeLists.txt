cmake_minimum_required(VERSION 3.24)
project(_STL00Algorithms)

set(CMAKE_CXX_STANDARD 20)

add_executable(00Intro 100algorithmsIntro.cpp)
add_executable(01Lambdas 101lambdas.cpp)
add_executable(02LambdasReturnType 102LambdasReturnType.cpp)
add_executable(02.4LambdaTransform 104Lambda_transform.cpp)
add_executable(02.6LambdaTransformReduce 106LamdaTransform_reduce.cpp)
add_executable(02.8PipedLambdas 108PipedLambdas.cpp)
add_executable(03Sort 202SortWithSpaceShip.cpp)

