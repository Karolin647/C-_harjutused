#ifndef P6H2_H
#define P6H2_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Auto {
private:
    string mark;
    string energiaklass;
    double kytusekulu_liitrites;

public:
    Auto(): mark{""}, energiaklass{""}, kytusekulu_liitrites{0.0}{};
    Auto(string mark, string energiaklass, double kytusekulu): mark{mark}, energiaklass{energiaklass}, kytusekulu_liitrites{kytusekulu}{};
    ~Auto(){
        cout << mark << " destruktoris\n";
    }
    
    double get_kytusekulu(){
        return kytusekulu_liitrites;
    }
    string get_mark(){
        return mark;
    }
    string get_klass(){
        return energiaklass;
    }
    friend ostream& operator<<(ostream& os, const Auto& a);
};

Auto* looAuto(const string& rida);
vector<Auto*>* loeAutod(const string& fail);
Auto* vahima_kuluga(vector<Auto*>* autod);
void kustutaAutod(vector<Auto*>* autod);

#endif