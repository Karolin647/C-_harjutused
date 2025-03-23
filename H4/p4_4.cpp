#include "p4_4.h"
#include <string>
#include <iostream>
using namespace std;

int main(){
    Massiiv<int> m{};
    m.lisaElement(5);
    m.lisaElement(8);
    m.lisaElement(5);
    m.lisaElement(5);
    m.print();
    m.kustutaElement();
    m.print();
    m.lisaElement(25);
    m.asendaElement(m.getElement(0), 9);
    m.print();
    cout << m.getElement(8) << '\n';
    cout << boolalpha << m.kasTais() << '\n';
    cout << m.vabuKohti() << " "  << m.kasSisaldub(23) << " " << m.getSuurus() << '\n';
    return 0;
}