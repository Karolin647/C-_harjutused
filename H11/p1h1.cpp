#include "p1h1.h"

PahupidiArv::PahupidiArv(int arv_) : arv(arv_) {}

PahupidiArv::PahupidiArv() : arv{0} {}

int PahupidiArv::get(){
    return arv;
}

void PahupidiArv::set(int uus){
    arv = uus;
}

PahupidiArv::PahupidiArv(PahupidiArv& ra) {
    arv = ra.get();
}

PahupidiArv::PahupidiArv(PahupidiArv&& ra) {
    arv = ra.get();
    ra.set(0);
}

PahupidiArv::~PahupidiArv(){
    cout << "destruktoris" << endl;
}

