#include "prax.h"
using namespace std;

void tryki(std::vector<int> v1){
    for (auto& el : v1) {
        cout << el <<  " ";
    }
    cout << endl;
}

int main() {
    vector<int> v1{10, 11, 5, 3, 3};
    vector<int> v2{3, 5, 3, 5, 1};
    vector<int> v3{};
    tryki(v1); // kuvab elemendid ekraanile
    tryki(v2);
    yhisosa(v1, v2, v3);
    cout << "v1 ja v2 ühisosa:\n";
    tryki(v3);
    v3.clear();
    yhend(v1, v2, v3);
    cout << "v1 ja v2 ühend:\n";
    tryki(v3);
    v3.clear();
    vahe(v1, v2, v3);
    cout << "v1 ja v2 vahe:\n";
    tryki(v3); 
}