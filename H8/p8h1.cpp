#include "p8h1.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <memory>

using namespace std;

unique_ptr<int[]> loo_andmed(int pikkus) {
    if (pikkus <= 0) return nullptr;
    
    unique_ptr<int[]> andmed (new int (pikkus)) ;
    srand(time(nullptr));
    for (int i = 0; i < pikkus; i++) {
        andmed[i] = rand() % 100;
    }
    return andmed;
}

shared_ptr<vector<int>> loe_andmed(string* failinimi) {
    ifstream fail(*failinimi);
    if (!fail) return nullptr;
    
    auto andmed = make_shared<vector<int>>();
    int arv;
    while (fail >> arv) {
        andmed->push_back(arv);
    }
    fail.close();
    return andmed;
}

void tootle_andmeid(weak_ptr<unique_ptr<int[]>> andmed, int pikkus) {
    if (andmed.lock()) { 
    
    int summa = 0;
    for (int i = 0; i < pikkus; i++) {
        summa += (*andmed.lock())[i];
    }
    double keskmine = static_cast<double>(summa) / pikkus;
    
    cout << "Massiivi summa: " << summa << endl;
    cout << "Massiivi keskmine: " << keskmine << endl;
    
    for (int i = 0; i < pikkus; i++) {
        (*andmed.lock())[i] = -abs((*andmed.lock())[i]);
    }
}
}

void tootle_andmeid_vektoris(weak_ptr<vector<int>> andmed) {
    if (andmed.lock() && !(andmed.lock()->empty())) {
    
    int summa = 0;
    for (int arv : *(andmed.lock())) {
        summa += arv;
    }
    double keskmine = static_cast<double>(summa) / andmed.lock()->size();
    
    cout << "Vektori summa: " << summa << endl;
    cout << "Vektori keskmine: " << keskmine << endl;
}
}



// Testfunktsioon
int main() {
    /*int pikkus = 10;
    unique_ptr<int[]> massiiv = loo_andmed(pikkus);
    int list_a[pikkus];
    for(int i = 0; i<pikkus; i++){
        list_a[i] = massiiv[i];
    }
    auto massiiv_1 = make_shared<int[]>(list_a);
    
    if (massiiv_1) {
        cout << "Loodud massiiv: ";
        for (int i = 0; i < pikkus; i++) {
            cout << (*massiiv_1)[i] << " ";
        }
        cout << endl;
        weak_ptr<unique_ptr<int[]>> massiiv_2{(massiiv_1)};
        tootle_andmeid(massiiv_2, pikkus);
        
        cout << "Muudetud massiiv: ";
        for (int i = 0; i < pikkus; i++) {
            cout << massiiv[i] << " ";
        }
        cout << endl;
    }*/
    
    string failinimi = "andmed.txt";
    auto vektor = loe_andmed(&failinimi);
    
    if (vektor) {
        cout << "Loetud vektor: ";
        for (int arv : *vektor) {
            cout << arv << " ";
        }
        cout << endl;
        weak_ptr<vector<int>> vec{vektor};
        tootle_andmeid_vektoris(vec);
    }
    
    return 0;
}