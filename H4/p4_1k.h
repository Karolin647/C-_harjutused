#ifndef P4_1K_H
#define P4_1K_H
#include <string>
#include <concepts>
#include <typeinfo>
#include <iostream>
using namespace std;

template<typename T, int N = 10>
T liidaJaPiira(T a, T b){
    return (a+b < N)? a+b:N;
}

#endif