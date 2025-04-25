#ifndef PRAX_H
#define PRAX_H
#include <math.h>
#include <iostream>
using namespace std;

class PahupidiArv
{
private:
    /* data */
    int arv;
public:
    PahupidiArv(int arv_);
    PahupidiArv();
    PahupidiArv(PahupidiArv& ra);
    PahupidiArv(PahupidiArv&& ra);
    int get();
    void set(int uus);
    ~PahupidiArv();
    PahupidiArv& operator=(PahupidiArv& ra) {
        if(this != &ra){
            arv = ra.get();
        }
        return *this;
    }

    PahupidiArv& operator=(PahupidiArv&& ra) {
        if(this != &ra){
            arv = ra.get();
        }
        ra.set(0);
        return *this;
    }

    void operator+=(PahupidiArv ra){
        arv = arv - ra.get();
    }

    void operator-=(PahupidiArv ra){
        arv = arv + ra.get();
    }

    void operator*=(PahupidiArv ra){
        arv = round(arv / ra.get());
    }

    void operator/=(PahupidiArv ra){
        arv = arv * ra.get();
    }

    friend ostream& operator<<(ostream& os, PahupidiArv& c){
        return os << "arv: " << c.get();
    }
};



#endif