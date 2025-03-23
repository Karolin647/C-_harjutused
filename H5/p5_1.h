#ifndef P4_4_H
#define P4_4_H
#include <string>
#include <iostream>
using namespace std;

template<typename T> 
void vaheta_ref (T& x, T& y) {
    T temp = x;
    x = y;
    y = temp;
}
template<typename T> 
void vaheta_ptr (T* x, T* y){
    T temp = *x;
    *x = *y;
    *y = temp;
}

#endif