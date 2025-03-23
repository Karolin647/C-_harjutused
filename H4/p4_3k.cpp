#include "p4_3k.h"
#include <iostream>
using namespace std;

int main(){
    double a = 1.2;
    float b = 2.0;
    int c = 3;
    string a_s{"tere "};
    char b_s{'c'};
    cout << liida(a, b) << '\n';
    cout << liida(a,c) << '\n';
    cout << liida(c,c) << '\n';
    cout << liida(a_s,b_s) << '\n';
    cout << liida(a_s,b) << '\n';
    cout << liida(c,b_s) << '\n';
    cout << OnVahemikus<4>(1,3) << '\n';

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