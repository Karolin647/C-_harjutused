#ifndef PRAK_13_3
#define PRAK_13_3

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Pitsa{
    private:
    string nimetus;
    float hind;
    public:
    Pitsa(string nnimetus, float nhind) : nimetus(nnimetus), hind(nhind) {}
    string getNimetus(){return nimetus;}
    float getHind(){return hind;}
    friend ostream& operator<<(ostream& os, Pitsa &pitsa){
        return os << pitsa.getNimetus() << " : " << pitsa.getHind();
    }

};

class Tellimus{
    private:
    string tellija;
    vector<Pitsa> pitsad;
    int ooteAeg;
    public:
    Tellimus(string ntellija, int nooteAeg, vector<Pitsa> npitsad) : tellija(ntellija), ooteAeg(nooteAeg), pitsad(npitsad) {
    }

    string getTellija() {return tellija;}
    int getOoteaeg() {return ooteAeg;}
    vector<Pitsa> getPitsad () {return pitsad;}

    friend ostream& operator<<(ostream& os, Tellimus &tellimus);

    float maksumus();
};

class LiigaPikkOotamineErind{
    public:
    string teade;
    LiigaPikkOotamineErind(string nteade) : teade(nteade) {}
};

#endif