#include "p6h2.h"
#include <fstream>
#include <sstream>
using namespace std;

ostream& operator<<(ostream& os, Auto* a){
    os << "Auto mark: " << a->get_mark() << "; energiaklass: " << a->get_klass() << "; kytusekulu: " << a->get_kytusekulu() << '\n';
    return os;
}

Auto* looAuto(const string& rida){
    stringstream ss{rida};
    string mark, energiaklass;
    double kytusekulu;
    
    if (getline(ss, mark, ';') && getline(ss, energiaklass, ';') && (ss >> kytusekulu)) {
        return new Auto(mark, energiaklass, kytusekulu);
    }
    return nullptr;
}

vector<Auto*>* loeAutod(const string& fail){
    vector<Auto*>* autod = new vector<Auto*>;
    ifstream sisse(fail);
    if (!sisse){
        return nullptr;
    }
    string rida;
    while(getline(sisse, rida)){
        autod->push_back(looAuto(rida));
    }
    sisse.close();
    return autod;
}

Auto* vahima_kuluga(vector<Auto*>* autod){
    Auto* auto_min = (*autod)[0];
    for(Auto* autoObj: *autod){
        if(auto_min->get_kytusekulu() > autoObj->get_kytusekulu()){
            auto_min = autoObj;
        }
    }
    return auto_min;
}

void kustutaAutod(vector<Auto*>* autod){
    for(Auto* autoObj: *autod){
        delete autoObj;
    }
    delete autod;
}

int main() {
    string failinimi = "autod.txt";
    vector<Auto*>* autod = loeAutod(failinimi);

    if (!autod || autod->empty()) {
        cout << "Autode lugemine ebaõnnestus või fail on tühi!" << '\n';
        return 1;
    }

    cout << "Autod failist:\n";
    for (Auto* autoObj : *autod) {
        cout << autoObj;
    }

    Auto* minAuto = vahima_kuluga(autod);
    if (minAuto) {
        cout << "\nVähima kütusekuluga auto:\n" << minAuto << '\n';
    }

    kustutaAutod(autod);

    return 0;
}