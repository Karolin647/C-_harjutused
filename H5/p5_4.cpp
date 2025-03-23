#include "p5h4.h"
#include <iostream>
#include <cmath>
using namespace std;

bool lahenda_1(double a, double b, double c, double& x1, double& x2){
    if(a==0){
        return false;
    }
    if(b*b-4*a*c < 0){
        return false;
    }
    x1 = (-b+sqrt(b*b-4*a*c))/2;
    x2 = (-b-sqrt(b*b-4*a*c))/2;
    return true;
}

bool lahenda_2(double* a, double* b, double* c, double& x1, double& x2){
    if((*b)*(*b)-4*(*a)*(*c) < 0){
        return false;
    }
    x1 = (-(*b)+sqrt((*b)*(*b)-4*(*a)*(*c)))/2;
    x2 = (-(*b)-sqrt((*b)*(*b)-4*(*a)*(*c)))/2;
    return true;
}

bool lahenda_3(double& a, double& b, double& c, double* x1, double* x2){
    if(b*b-4*a*c < 0){
        return false;
    }
    *x1 = (-b+sqrt(b*b-4*a*c))/2;
    *x2 = (-b-sqrt(b*b-4*a*c))/2;
    return true;
}

bool lahenda_4(double* a, double* b, double* c, double* x1, double* x2){
    if((*b)*(*b)-4*(*a)*(*c) < 0){
        return false;
    }
    *x1 = (-(*b)+sqrt((*b)*(*b)-4*(*a)*(*c)))/2;
    *x2 = (-(*b)-sqrt((*b)*(*b)-4*(*a)*(*c)))/2;
    return true;
}

int main(){
    double a{1}, b{4}, c{0}, x1{0}, x2{0};
    double* p_a{&a};
    double* p_b{&b};
    double* p_c{&c};
    double* p_x1{&x1};
    double*  p_x2{&x2};
    double& ref_a{a};
    double& ref_b{b};
    double& ref_c{c};
    double& ref_x1{x1};
    double& ref_x2{x2};
    lahenda_1(a, b, c, ref_x1, ref_x2);
    cout << "Lahend 1: " << x1 << ", " << x2 << '\n';
    b=5;
    lahenda_2(p_a, p_b, p_c, ref_x1, ref_x2);
    cout << "Lahend 1: " << x1 << ", " << x2 << '\n';
    b=3;
    lahenda_3(ref_a, ref_b, ref_c, p_x1, p_x2);
    cout << "Lahend 1: " << x1 << ", " << x2 << '\n';
    b=10;
    lahenda_4(p_a, p_b, p_c, p_x1, p_x2);
    cout << "Lahend 1: " << x1 << ", " << x2 << '\n';
    return 0;
}