#ifndef PRAK_14_1
#define PRAK_14_1
#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Raamat {
    private:
    string pealkiri;
    string autor;
    string sari;
    public:
    Raamat() = default;
    Raamat(string _pealkiri, string _autor, string _sari) : pealkiri(_pealkiri), autor(_autor), sari(_sari) {}
    friend bool operator==( Raamat& lhs,  Raamat& rhs);
    string getPealkiri() const { return pealkiri;}
    string getAutor() const { return autor;}
    string getSari() const {return sari;}
    friend ostream& operator<<(ostream& os,const Raamat& obj);
    void setSari(string _sari);
};

template <typename T>
class Data {
    public:
    vector<T> v;
    Data() = default;
    ~Data() {};
    void lisaObjekt(T& obj);
    T getFromIndex(int i) {
       return v.at(i);
    }
    int getFromObject(T& obj) {
        int i = 0;
        for(auto& x : v) {
            if(x == obj) {
                return i;
            }
            i++;
        }
        return -1;
    }
    void Kuva(){
        for(auto& x : v) {
            cout << x << endl;
        }
    }
};

template<typename T>
void Data<T>::lisaObjekt(T& obj){
        v.push_back(obj);
}


class Sari {
private:
    string nimi;
    vector<Raamat> raamatud;
public:
    string getNimi() { return nimi; }
    vector<Raamat>& getRaamatud() { return raamatud; }
    Sari(string _nimi): nimi{_nimi}, raamatud{} {};
    void lisaRaamat(Raamat& raamat);
    void kustutaRaamat(Raamat& raamat);
    friend ostream& operator<<(ostream& os, Sari& sari);
};

class Sarjad {
private:
    map<string, vector<Raamat>*> raamatud;
public:
    void lisaRaamat(Raamat& raamat);
    void muudaSari(Raamat& raamat);
    void kustutaRaamat(Raamat& raamat);
    void lisaSari(Sari& sari);
    void kustutaSari(Sari& sari);
    friend ostream& operator<<(ostream& os, Sarjad& sarjad);
};
#endif