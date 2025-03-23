#include <iostream>
using namespace std;

int main(){
    int kaal, aeg;
    cout << "Sisesta kaal: ";
    cin >> kaal;
    cout << "Sisesta aeg minutites: ";
    cin >> aeg;
    cout << "Tegevus" << "\t\t\t" << "Aeg min Kulutatud kcal\n";
    cout << "----------------------------------------------\n";
    cout << "Kõndimine" << "\t\t" << aeg << "\t" << kaal * aeg / 60.0 * 4 << "\n";
    cout << "Treppidel käimine" << "\t" << aeg << "\t" << kaal * aeg / 60.0 * 5.5 << "\n";
    cout << "Ujumine" << "\t\t\t" << aeg << "\t" << kaal * aeg / 60.0 * 10 << "\n";
    cout << "Korvpall" << "\t\t" << aeg << "\t" << kaal * aeg / 60.0 * 8 << "\n";
    return 0;

}
