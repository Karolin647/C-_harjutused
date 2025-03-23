#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string lyhendaja(string nimi){
    if (nimi.empty()){
        cout << "Viga";
        return "";
    }

    int pos = nimi.find_last_of(' ');
    string pere = nimi.substr(pos + 1, nimi.length() - 1);
    nimi = nimi.substr(0, pos+1);
    pos = nimi.find(" ");
    cout << nimi << endl;
    cout << pos << endl;
    string out = pere + " ";
    string part_name;
    int kriips;
    while ( nimi.length() - 1 >= pos && pos >= 0){
        part_name = nimi.substr(0, pos);
        cout << part_name << endl;
        nimi = nimi.substr(pos + 1);
        kriips = part_name.find("-");
        while ( part_name.length() - 1 >= kriips && kriips >= 0){
            out += part_name.substr(0,1) + "-";
            part_name = part_name.substr(kriips + 1);
            kriips = part_name.find("-");
        }
        cout << nimi << endl;
        out += part_name.substr(0,1) + ". ";
        pos = nimi.find(" ");
        cout << pos << endl;
    }
    return out;
}

int main () {
    string nimi{"Timur-Mai-Mari Mikk Kedrov"};
    string pere = lyhendaja(nimi);
    cout << pere;
    return 0;
}