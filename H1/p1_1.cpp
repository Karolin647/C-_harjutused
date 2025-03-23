#include <iostream>
using namespace std;


int main(){
    cout << "Sisesta täisarv: \n";
    int number;
    cin >> number;
    cout << "Viimane number: " << number % 10 << "\n";
    cout << (number>>1) << "\n";
    cout << (number>>1<<2);
}

// g++ -std=c++20 file.cpp -o file