#include "p6h1.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int* loo_andmed(int pikkus) {
    if (pikkus <= 0) return nullptr;
    
    int* andmed = new int[pikkus];
    srand(time(nullptr));
    for (int i = 0; i < pikkus; i++) {
        andmed[i] = rand() % 100;
    }
    return andmed;
}

vector<int>* loe_andmed(string* failinimi) {
    ifstream fail(*failinimi);
    if (!fail) return nullptr;
    
    vector<int>* andmed = new vector<int>;
    int arv;
    while (fail >> arv) {
        andmed->push_back(arv);
    }
    fail.close();
    return andmed;
}

void tootle_andmeid(int* andmed, int pikkus) {
    if (!andmed) return;
    
    int summa = 0;
    for (int i = 0; i < pikkus; i++) {
        summa += andmed[i];
    }
    double keskmine = static_cast<double>(summa) / pikkus;
    
    cout << "Massiivi summa: " << summa << endl;
    cout << "Massiivi keskmine: " << keskmine << endl;
    
    for (int i = 0; i < pikkus; i++) {
        andmed[i] = -abs(andmed[i]);
    }
}

void tootle_andmeid_vektoris(vector<int>* andmed) {
    if (!andmed || andmed->empty()) return;
    
    int summa = 0;
    for (int arv : *andmed) {
        summa += arv;
    }
    double keskmine = static_cast<double>(summa) / andmed->size();
    
    cout << "Vektori summa: " << summa << endl;
    cout << "Vektori keskmine: " << keskmine << endl;
}

// Funktsioon andmete vabastamiseks
void kustuta_andmed(int* massiiv, vector<int>* vektor) {
    delete[] massiiv;
    delete vektor;
}

// Testfunktsioon
int main() {
    int pikkus = 10;
    int* massiiv = loo_andmed(pikkus);
    
    if (massiiv) {
        cout << "Loodud massiiv: ";
        for (int i = 0; i < pikkus; i++) {
            cout << massiiv[i] << " ";
        }
        cout << endl;
        
        tootle_andmeid(massiiv, pikkus);
        
        cout << "Muudetud massiiv: ";
        for (int i = 0; i < pikkus; i++) {
            cout << massiiv[i] << " ";
        }
        cout << endl;
    }
    
    string failinimi = "andmed.txt";
    vector<int>* vektor = loe_andmed(&failinimi);
    
    if (vektor) {
        cout << "Loetud vektor: ";
        for (int arv : *vektor) {
            cout << arv << " ";
        }
        cout << endl;
        
        tootle_andmeid_vektoris(vektor);
    }
    
    kustuta_andmed(massiiv, vektor);
    return 0;
}