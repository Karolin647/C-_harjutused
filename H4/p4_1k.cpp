#include "p4_1k.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
    cout << liidaJaPiira(4, 1) << '\n';
    cout << liidaJaPiira(10, 100) << '\n';
    cout << liidaJaPiira<int, 0>(0, 1) << '\n';
    return 0;
}