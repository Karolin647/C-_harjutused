#ifndef P4_2K_H
#define P4_2K_H
#include <iostream>
#include <fstream>
#include <filesystem>
using namespace std;

template <typename T>
void looFailJaKirjuta(filesystem::path asukoht, T elemendid[], size_t arv) {
    ofstream fail(asukoht);
    if (!fail.is_open()) {
        cout << "Faili avamine ebaõnnestus: " << asukoht << '\n';
        return;
    }
    
    for (size_t i = 0; i < arv; i++) {
        fail << elemendid[i] << '\n';
    }
    fail.close();
}

#endif