#include "p12h1.h"
#include "p12h1.cpp"

int main() {
    vector<Tulemus> p; 
    loe_failist("test.txt", p);
    Osaleja obj1 ("38002055060", "Alex");
    Osaleja obj2 ("34501234215", "Matias");
    Lapsosaleja laps("60212243307", "Hans", "38002055060");
    cout << obj1 << endl << obj2 << endl << laps << endl;
}