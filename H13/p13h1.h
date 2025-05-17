#ifndef PRAK_13_1
#define PRAK_13_1
#include <iostream>
#include <string>
#include <exception>
#include <vector>

using namespace std;

class ArvuPole : public exception {
    public:
    string sonum;
    ArvuPole(string _sonum) : sonum{_sonum} {}
};

class PoleArv : public exception {
    public:
    string sonum;
    PoleArv(string _sonum) : sonum{_sonum} {}
};

class Arvulugeja {
    public:
    string var;
    Arvulugeja(string word) : var{word} {} 
    vector<int> getVector(string word);
};

void viska(int x);
#endif